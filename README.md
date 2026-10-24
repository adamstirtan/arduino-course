# Arduino Course

A custom, hands-on course for learning hardware electronics with the
Elegoo Complete Starter Kit for Arduino UNO — written for someone who
already knows how to code and wants to learn how the hardware actually
works.

The kit's included tutorial PDF is a reference manual, not a course: it
jumps straight to wiring diagrams and code dumps with almost no
explanation of *why* a circuit works. This course flips that around.
Every module teaches one hardware idea properly, then has you build it,
poke at it, and break it on purpose — because that's how the intuition
sticks.

## The Storyline

You are a newly recruited hardware hacker for a small underground crew.
Your handler drops you a mission brief at the start of each module, and
every circuit you build is a piece of field gear. The skills stack: you
can't crack the vault in the finale if you didn't learn to read a sensor
in Module 5.

Everything here is built with your own kit, in your own home — a heist
movie, not a how-to for breaking into things.

## What You Need

- Elegoo Complete Starter Kit for UNO (UNO R3 board, breadboard,
  jumper wires, LEDs, resistors, sensors, and modules included in the kit)
- A computer with the Arduino IDE installed (Mac, Windows, or Linux)
- No extra parts to buy — every module uses only what's in the kit

## How Each Module Works

Every module follows the same shape:

1. **Mission brief** — a short story setup for what you're building and why
2. **The concept** — the hardware idea in plain language, with real numbers
3. **The build** — wiring with your exact kit parts, and the code (kept
   short — the code is the easy part)
4. **Break it on purpose** — change a value, swap a wire, see what
   changes, and understand why
5. **Debrief** — what you just learned, tied back to the story

## The Modules

### Module 1 — First Contact
Setup and your first circuit. Getting the IDE running, uploading Blink,
and reading a wiring diagram without guessing. Build: the onboard LED,
then an external LED on the breadboard. The point: what a pin actually
does when you set it HIGH.

### Module 2 — Learn the Grid
Electricity, properly. Voltage, current, and resistance with real
numbers, Ohm's law, and why the resistor value matters. Builds: an LED
with different resistor values, series vs. parallel LEDs. The point:
never wire anything without knowing what current it will draw.

### Module 3 — The Door Panel
Digital inputs. Buttons, pull-up and pull-down resistors, debouncing,
and why a floating pin reads garbage. Builds: a button-controlled LED,
a tilt switch, a membrane keypad. The point: inputs are circuits too,
not just code reading a pin.

### Module 4 — Eyes and Ears
Analog and PWM. Analog input vs. digital, ADC resolution,
potentiometers, photocells, and PWM as fake-analog output. Builds: dimming
an LED with a knob, a light-controlled LED, RGB LED colour mixing,
passive buzzer tones. The point: the world is analog; the Arduino just
samples it.

### Module 5 — Surveillance Kit
Sensors that tell you something. Temperature and humidity (DHT11),
ultrasonic distance, PIR motion, sound, water level, joystick, IR remote,
accelerometer. Builds: one small working sensor each, with a "what does
this reading actually mean" check. The point: reading a datasheet and
calibrating a sensor.

### Module 6 — Exfiltration
Displays and output expansion. 7-segment displays, the 74HC595 shift
register, the LED dot matrix, and the LCD. Builds: a counter on a
7-segment display, scrolling text on the LCD, a thermometer that shows
real readings. The point: you run out of pins fast, and that's a solvable
problem.

### Module 7 — Time Locks and Keys
Time, memory, and communication. The real-time clock, RFID, and the
serial monitor as a debugging tool. Builds: a clock with an LCD, an RFID
"key" that triggers an action. The point: a project that remembers
things and talks back.

### Module 8 — Physical Access
Motors and power. DC motors, relays, stepper motors, and why you never
power a motor straight from an Arduino pin. Builds: a motor switched
with a transistor/relay, a stepper driven with a remote and a rotary
encoder. The point: switching real loads safely.

### The Finale — The Job
A complete field device built from everything before it: a
motion-triggered, RFID-gated, LCD-reporting gadget — a little vault
alarm, a door system, or a weather station for the safehouse. Completing
it is the end of the story arc.

## Reading the Course

The course is published as a website with GitHub Pages. All pages are
Markdown files under `docs/`, rendered with the Just the Docs Jekyll
theme (sidebar navigation, search, dark colour scheme).

- **Site:** https://adamstirtan.github.io/arduino-course
- **To enable it:** repo Settings → Pages → build from the `master`
  branch, `/docs` folder.

## Status

Course outline, storyline, and GitHub Pages scaffold are set. Module
content is coming next — each module page under `docs/` will be filled
in as it's written.
