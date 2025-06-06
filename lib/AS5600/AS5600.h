#ifndef AS5600_H
#define AS5600_H

#include <Arduino.h>
#include <Wire.h>

class AS5600
{
public:
    AS5600(float gear_ratio, TwoWire &wirePort = Wire, uint8_t address = 0x36);
    bool begin();
    void update();
    float getPosition();
    void setPosition(float position);
    float getSpeed();
    bool magnetDetected();

private:
    TwoWire *_wire;
    uint8_t _address;

    float _gear_ratio;
    float _lastRawAngle = 0.0;
    float _position = 0.0;
    float _speed = 0.0;
    unsigned long _lastUpdate = 0;

    uint8_t read8(uint8_t reg);
    uint16_t read12bit(uint8_t regHigh);
    float getRawAngle();
};

#endif
