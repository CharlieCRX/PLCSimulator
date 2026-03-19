#pragma once
#include <unordered_map>
#include <cstdint>
#include <vector>

class RegisterManager {
public:
  uint16_t read(uint16_t addr) const;

  void write(uint16_t addr, uint16_t value);

  std::vector<uint16_t> readBlock(
    uint16_t start,
    uint16_t count);

private:
  std::unordered_map<uint16_t, uint16_t> registers;
};