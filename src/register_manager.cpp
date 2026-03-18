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