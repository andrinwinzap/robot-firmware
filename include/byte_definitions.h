#ifndef BYTE_DEFINITIONS
#define BYTE_DEFINITIONS

#include <Arduino.h>

namespace Byte
{
    namespace Protocol
    {
        enum : uint8_t
        {
            START = 0xAA,
            ESCAPE = 0xAB,
            ESCAPE_MASK = 0x20,
            CRC8_POLY = 0x07
        };
    }

    namespace Command
    {
        enum : uint8_t
        {
            PING = 0x01,
            HOME = 0x02,
            POS = 0x03,
            LOAD_TRAJ = 0x04,
            EXEC_TRAJ = 0x05,
            FINISHED = 0x06,
            STATUS = 0x07,
            ESTOP = 0x08,
            ACK = 0xEE,
            NACK = 0xFF
        };
    }

    namespace Status
    {
        enum : uint8_t
        {
            IDLE = 0x01,
            HOMING = 0x02,
            EXECUTING_TRAJECTORY = 0x03,
        };
    }

    namespace Address
    {
        enum : uint8_t
        {
            BROADCAST = 0x00,
            MASTER = 0x01,
            ACTUATOR_1 = 0x02,
            ACTUATOR_2 = 0x03,
            ACTUATOR_3 = 0x04,
            ACTUATOR_4 = 0x05,
            ACTUATOR_5 = 0x06,
            ACTUATOR_6 = 0x07,
            TOOL = 0x08
        };
    }

    inline uint8_t mux_channel(uint8_t address)
    {
        switch (address)
        {
        case Byte::Address::ACTUATOR_1:
            return 0;
        case Byte::Address::ACTUATOR_2:
            return 1;
        case Byte::Address::ACTUATOR_3:
            return 2;
        case Byte::Address::ACTUATOR_4:
            return 3;
        case Byte::Address::ACTUATOR_5:
            return 4;
        case Byte::Address::ACTUATOR_6:
            return 5;
        case Byte::Address::TOOL:
            return 6;
        default:
            return 0;
        }
    }
}

#endif