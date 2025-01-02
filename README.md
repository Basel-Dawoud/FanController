# Fan Controller System

## Overview
This project implements a fan controller system based on the temperature readings from an LM35 sensor. The system adjusts the speed of a DC fan dynamically, depending on the temperature, using an ATmega microcontroller. The temperature and fan status are displayed on an LCD in real-time.

### Features
- **Dynamic Fan Control**: Adjusts fan speed in response to temperature thresholds.
- **LCD Display**: Shows the current temperature and fan status ("ON" or "OFF").
- **Temperature Monitoring**: Uses an LM35 sensor for accurate readings.
- **PWM Fan Speed Control**: Employs Pulse Width Modulation (PWM) to set fan speeds.

---

## System Design

### Hardware Requirements
1. **ATmega Microcontroller**
2. **LM35 Temperature Sensor**
3. **16x2 LCD**
4. **DC Motor (Fan)**
5. **Motor Driver IC** (e.g., L293D or equivalent)
6. **Power Supply** (5V for the MCU, motor supply as required)
7. **Resistors and Wires**

### Software
- **C Programming** using AVR libraries
- Modularized code for ADC, PWM, GPIO, and LCD functionalities

---

## File Descriptions

### `Application.c`
The main program for the fan controller system. Includes logic for:
- Reading the temperature using the LM35 sensor.
- Displaying the temperature and fan status on the LCD.
- Adjusting the fan speed based on predefined temperature thresholds.

### Supporting Modules
- **`adc.c/h`**: Handles ADC initialization and readings.
- **`lcd.c/h`**: Manages LCD initialization and display functions.
- **`lm35_sensor.c/h`**: Provides temperature readings from the LM35 sensor.
- **`DCMotor.c/h`**: Controls the DC motor's direction and speed.
- **`PWM.c/h`**: Generates PWM signals for motor speed control.
- **`gpio.c/h`**: Configures GPIO pins for peripheral communication.
- **`std_types.h` & `common_macros.h`**: Defines standard data types and reusable macros.

---

## Functionality

### Temperature Thresholds
- **90°C or Higher**: Fan runs at **75%** speed.
- **60–89°C**: Fan runs at **50%** speed.
- **30–59°C**: Fan runs at **25%** speed.
- **Below 30°C**: Fan turns **OFF**.

### Real-Time Display
The LCD shows:
- **Fan Status**: "ON" or "OFF".
- **Temperature**: Updated continuously in degrees Celsius.

---

## How to Use

### Setup
1. Connect the hardware as per the system design.
2. Compile and upload `Application.c` to the ATmega microcontroller.
3. Power the system.

### Operation
- The system starts with the fan turned off and the current temperature displayed.
- The fan speed adjusts dynamically based on the temperature sensor readings.

---

## Future Enhancements
- Add support for additional sensors or actuators.
- Integrate EEPROM for logging temperature data.
- Implement a graphical interface for advanced monitoring.

---

## Author
**Basel Dawoud**  
*Contact*: baseldawoud2003@gmail.com  
