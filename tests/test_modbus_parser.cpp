#include <gtest/gtest.h>
#include "protocol/modbus_parser.h"

TEST(ModbusParser, ParseFunction03) {
  ModbusParser parser;

  std::vector<uint8_t> data = 
  {
    0x00, 0x01, // 对应请求的序号
    0x00, 0x00, // Modbus 协议
    0x00, 0x06, // 长度
    0x01,       // 单元 ID
    0x03,       // 功能码
    0x00, 0x64, // 起始地址
    0x00, 0x03  // 寄存器数量
  };

  auto req = parser.parse(data);

  EXPECT_EQ(req.function_code, 3);
  EXPECT_EQ(req.start_address, 100);
  EXPECT_EQ(req.quantity, 3);
}

TEST(ModbusParser, InvalidData)
{
  ModbusParser parser;

  std::vector<uint8_t> data = {0x01, 0x02};

  EXPECT_ANY_THROW(parser.parse(data));
}