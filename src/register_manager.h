#pragma once
#include <unordered_map>
#include <cstdint>

class RegisterManager {
public:
  uint16_t read(uint16_t addr) const;

  void write(uint16_t addr, uint16_t value);

private:
  std::unordered_map<uint16_t, uint16_t> registers;
};