# Mini v2 Cyphal application example

This repository is an example of a simple Cyphal application written for [Mini v2](https://docs.raccoonlab.co/guide/can_pwm/can_pwm_mini_v2.html#pinout) node.

## 1. Prerequisites

You are expected to use the following software:
- [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) or [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html),
- Repository with minimal Cyphal implementation for stm32 based on [libcanard](https://github.com/OpenCyphal/libcanard), [o1heap](https://github.com/pavel-kirienko/o1heap) and other libraries,
- [Yukon](https://github.com/OpenCyphal-Garage/yukon).

Hardware requirements:
- Mini v2 node
- stm32 sniffer and programmer (for example [RL sniffer and programmer](https://docs.raccoonlab.co/guide/programmer_sniffer/))


## 2. Brief hardware description

Refer to the [Mini v2 hardware](https://docs.raccoonlab.co/guide/can_pwm/can_pwm_mini_v2.html#pinout) page for the details.

| View | Top view | Bot view |
| ---- | --- | ------ |
| <img src="https://docs.raccoonlab.co/assets/img/mini_v2_view.bbf1e631.png" alt="drawing"> | <img src="https://docs.raccoonlab.co/assets/img/mini_v2_view_top.6b0ef99e.png" alt="drawing"> | <img src="https://docs.raccoonlab.co/assets/img/mini_v2_view_bottom.ee41f6d5.png" alt="drawing">|

Pinout description:

<img src="https://docs.raccoonlab.co/assets/img/mini_v2_pinout.c14a3021.png" alt="drawing">

## 3. STM32CubeMX

In this example, the project has the following pinout configuration that is similar to what we have for the original CAN-PWM firmware.

<img src="assets/stm32cubemx.png" alt="drawing">

## 4. Usage

You are expected to use Makefile to work with the project.

**Step 1. Clone the repository with submodules**

```bash
git clone https://github.com/RaccoonlabDev/mini_v2_node --recursive
cd mini_v2_node
git submodule update --init --recursive
```

**Step 2. Connect Sniffer and programmer to Mini v2 node.**

For details of the connection refer to:
- [the Programmer connection](https://docs.raccoonlab.co/guide/programmer_sniffer/programmer.html) page,
- [the Sniffer connection](https://docs.raccoonlab.co/guide/programmer_sniffer/sniffer.html#_4-1-cyphal-usage) page.

**Step 3. Build the project and upload the firmware**

```bash
make build
make upload
```

**Step 4. Setup the environment and run Yukon**

```bash
source scripts/init.sh
~/Download/Yukon
```