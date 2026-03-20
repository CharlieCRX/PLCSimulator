#pragma once

#include <vector>
#include <cstdint>
#include "modbus_request.h"

class ModbusParser {
  public:
    ModbusRequest parse(const std::vector<uint8_t>& data);
};
