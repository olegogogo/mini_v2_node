/**
 * This program is free software under the GNU General Public License v3.
 * See <https://www.gnu.org/licenses/> for details.
 * Author: Dmitry Ponomarev <ponomarevda96@gmail.com>
 */

#include "led.hpp"
#include <cstddef>
#include "main.h"

namespace Board {

#ifndef INTERNAL_LED_RED_GPIO_Port
    #define INTERNAL_LED_RED_GPIO_Port      INT_RGB_LED_RED_GPIO_Port
    #define INTERNAL_LED_RED_Pin            INT_RGB_LED_RED_Pin
    #define INTERNAL_LED_GREEN_GPIO_Port    INT_RGB_LED_GREEN_GPIO_Port
    #define INTERNAL_LED_GREEN_Pin          INT_RGB_LED_GREEN_Pin
    #define INTERNAL_LED_BLUE_GPIO_Port     INT_RGB_LED_BLUE_GPIO_Port
    #define INTERNAL_LED_BLUE_Pin           INT_RGB_LED_BLUE_Pin
#endif

static void write_red(bool enabled) {
    GPIO_PinState state = enabled ? GPIO_PIN_RESET : GPIO_PIN_SET;
    HAL_GPIO_WritePin(INTERNAL_LED_RED_GPIO_Port, INTERNAL_LED_RED_Pin, state);

#ifdef EXT_RGB_LED_RED_GPIO_Port
    HAL_GPIO_WritePin(EXT_RGB_LED_RED_GPIO_Port, EXT_RGB_LED_RED_Pin, state);
#endif
}
static void write_green(bool enabled) {
    GPIO_PinState state = enabled ? GPIO_PIN_RESET : GPIO_PIN_SET;
    HAL_GPIO_WritePin(INTERNAL_LED_GREEN_GPIO_Port, INTERNAL_LED_GREEN_Pin, state);

#ifdef EXT_RGB_LED_GREEN_GPIO_Port
    HAL_GPIO_WritePin(EXT_RGB_LED_GREEN_GPIO_Port, EXT_RGB_LED_GREEN_Pin, state);
#endif
}
static void write_blue(bool enabled) {
    GPIO_PinState state = enabled ? GPIO_PIN_RESET : GPIO_PIN_SET;
    HAL_GPIO_WritePin(INTERNAL_LED_BLUE_GPIO_Port, INTERNAL_LED_BLUE_Pin, state);

#ifdef EXT_RGB_LED_BLUE_GPIO_Port
    HAL_GPIO_WritePin(EXT_RGB_LED_BLUE_GPIO_Port, EXT_RGB_LED_BLUE_Pin, state);
#endif
}

void Led::set(Color color) {
    auto color_byte = std::byte(static_cast<uint8_t>(color));

    auto red = static_cast<bool>(color_byte & std::byte{1 << 2});
    auto green = static_cast<bool>(color_byte & std::byte{1 << 1});
    auto blue = static_cast<bool>(color_byte & std::byte{1 << 0});

    write_red(red);
    write_green(green);
    write_blue(blue);
}

void Led::reset() {
    write_red(false);
    write_green(false);
    write_blue(false);
}

void Led::blink(Color first, Color second) {
    auto crnt_time_ms = HAL_GetTick();
    auto color = (crnt_time_ms % 1000 > 500) ? first : second;
    set(color);
}


}  // namespace Board
