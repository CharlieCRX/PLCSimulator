#pragma once

#include <cstdint>

struct ModbusRequest
{
  uint8_t  function_code;
  uint16_t start_address;
  uint16_t quantity;
};