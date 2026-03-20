#include "modbus_parser.h"
#include <stdexcept>

ModbusRequest ModbusParser::parse(const std::vector<uint8_t>& data) {
  // 如果字节数小于 12，直接抛出异常
  if (data.size() < 12) {
      throw std::invalid_argument("Request packet too short");
  }
  ModbusRequest req{};

  req.function_code = data[7];
  req.start_address = (data[8] << 8) | data[9];
  req.quantity = (data[10] << 8) | data[11];

  return req;
}