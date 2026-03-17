#include <gtest/gtest.h>
#include "register_manager.h"

TEST(RegisterManager, WriteRead)
{
  RegisterManager rm;

  rm.write(100, 42);

  EXPECT_EQ(rm.read(100), 42);
}


TEST(RegisterManager, DefaultValue)
{
  RegisterManager rm;

  EXPECT_EQ(rm.read(999), 0);
}