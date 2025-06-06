#include "default.h"
#include "stepper-default.h"
#include <byte_definitions.h>

constexpr bool DUMMY_MODE = true;

// Gearbox
constexpr float GEAR_RATIO = 13.0;

// Serial Communication Protocol
constexpr int PROTOCOL_ADDRESS = Byte::Address::ACTUATOR_3;