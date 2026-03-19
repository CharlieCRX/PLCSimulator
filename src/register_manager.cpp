#include "register_manager.h"

uint16_t RegisterManager::read(uint16_t addr) const {
  auto it = registers.find(addr);

  if (it == registers.end()) {
    return 0;
  }

  return it->second;
}

void RegisterManager::write(uint16_t addr, uint16_t value) {
  registers[addr] = value;
}

std::vector<uint16_t> RegisterManager::readBlock(uint16_t start, uint16_t count) {
  std::vector<uint16_t> result;
  for (uint16_t i = 0; i < count; i++) {
    result.push_back(read(start + i));
  }

  return result;
}