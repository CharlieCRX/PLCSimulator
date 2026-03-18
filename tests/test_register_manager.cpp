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

TEST(RegisterManager, Overwrite)
{
  RegisterManager rm;

  rm.write(100, 10);
  rm.write(100, 20);
  rm.write(100, 30);

  EXPECT_EQ(rm.read(100), 30);
}