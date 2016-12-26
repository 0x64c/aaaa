# aaaa
GCW0 port of aaaa based on original linux port codebase
## Progress:
- Controls
- Graphics code fixes
- Save file handling
- Haptic feedback
- G-Sensor
- Commandline arguments
- Titlecard by hi-ban

## Controls:
- A: Confirm/Sword
- B: Jump
- X: Shout/Confirm Quit
- Y: Fire Gun
- L: Aim gun
- R: Look
- Start Enter/Menu
- Select Esc/Torch
- DPAD: Movement
- Joypad: Analogue movement
- HOLD: Exit to OS immediately
- POWER: Re-centre G-Sensor
- G-Sensor: Camera tilt

## Known bugs:
- Force feedback is glitchy due to GCW0's driver, so disabled by Makefile (needs firmware fix)

## Note:
- PCLINUX build requires at least libshake v0.3.0; please build and install it.
- [GET LIBSHAKE HERE](https://github.com/zear/libShake)
- GCW build also requires libshake, but you may need to update your toolchain.
- Command line options are supported. "./aaaa --help" to list.

## Build notes:
- "env PLATFORM=PC make" to build PCLINUX build
- "make opk" to build GCW opk build

