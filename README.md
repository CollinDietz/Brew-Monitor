# Brew-Monitor
Particle IO project to use a Dallas DS18B20 temperature sensor to remotely monitor a fermenting home brew

## Hardware
This project was built using the following pieces of hardware
- [Particle Photon](https://store.particle.io/products/photon)
- [Waterproof DS18B20 Digital temperature sensor](https://www.adafruit.com/product/381)

Although the project could be done using any internet connected board capable of running the Particle libraries

## Dependencies
The sensor is read using the `DS18.h` header in the `OneWire` library provided by Particle.io as a verified library
