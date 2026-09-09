# 🏠 Mini Smart Home — Arduino

A small Arduino-based **Mini Smart Home prototype** that demonstrates how sensors can be used to automate and improve the safety of a home.

The project uses separate **User-Defined Functions (UDFs)** for each sensor feature, keeping the code modular and easy to understand.

## ✨ Features

### 💡 1. Automatic Lighting — LDR

The LDR (Light Dependent Resistor) detects the surrounding light level.

* When the environment becomes dark → the light turns **ON**
* When there is enough light → the light turns **OFF**

### 🚨 2. Security System — IR Sensor

The IR sensor is used to detect an object/person near the entrance.

When an object is detected:

* 🔴 Alarm LED turns **ON**
* 🔊 Buzzer turns **ON**

When no object is detected:

* Alarm LED turns **OFF**
* Buzzer turns **OFF**

### 🌡️ 3. Temperature Monitoring — NTC

An NTC thermistor will be used to monitor temperature.

* Normal temperature → normal status
* High temperature → warning indication

This feature will be added to the project after the LDR and IR systems.

---

## 🔧 Hardware

| Component      |    Quantity | Purpose              |
| -------------- | ----------: | -------------------- |
| Arduino Nano   |           1 | Main controller      |
| LDR sensor     |           1 | Light detection      |
| IR sensor      |           1 | Security detection   |
| NTC thermistor |           1 | Temperature sensing  |
| LED            | As required | Status/room lighting |
| 330Ω resistor  | As required | LED current limiting |
| Buzzer         |           1 | Alarm                |
| Breadboard     |           1 | Prototyping          |
| Jumper wires   | As required | Connections          |

---

## 📌 Pin Configuration

| Arduino Pin | Component | Function                 |
| ----------- | --------- | ------------------------ |
| A0          | LDR       | Light level input        |
| D2          | White LED | Automatic room light     |
| D3          | IR sensor | Security detection       |
| D4          | Red LED   | Security alarm indicator |
| D5          | Buzzer    | Security alarm           |
| A1          | NTC       | Temperature input        |

> Pin assignments may change during development.

---

## 💻 Software

The project is programmed using the **Arduino IDE**.

The code is organized into separate functions:

```cpp
void ldrControl();
void securityControl();
void temperatureControl();
```

The main `loop()` calls each function:

```cpp
void loop() {
    ldrControl();
    securityControl();
    temperatureControl();
}
```

This makes the program modular and allows each sensor system to be developed and tested separately.

---

## 🧠 Working Principle

The Arduino continuously reads data from the sensors.

```text
              ┌─────────────────┐
              │  Arduino Nano   │
              └────────┬────────┘
                       │
        ┌──────────────┼──────────────┐
        │              │              │
        ▼              ▼              ▼
       LDR             IR             NTC
        │              │              │
        ▼              ▼              ▼
   Auto Light      Security        Temperature
                     Alarm           Monitor
```

The project demonstrates three important applications of sensors:

**Automation + Security + Environmental Monitoring**

---

## 🚧 Project Status

* [x] Arduino Nano setup
* [x] LDR automatic lighting
* [x] USD security system
* [x] NTC temperature monitoring
* [x] Combine all systems
* [ ] Build miniature house model
* [ ] Final testing

---

## 🎯 Objective

The main objective of this project is to demonstrate how an Arduino can integrate multiple sensors to create a simple **smart home system**.

The project focuses on practical applications of:

* Sensor interfacing
* Digital and analog input
* Output control
* Conditional programming
* Modular programming using functions
* Arduino-based automation

---

## 👨‍💻 Project

**Project:** Mini Smart Home
**Platform:** Arduino Nano
**Development Environment:** Arduino IDE
**Type:** Arduino Sensor & Automation Project
