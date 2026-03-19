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


TEST(RegisterManager, ReadBlock)
{
  RegisterManager rm;
  rm.write(100, 10);
  rm.write(101, 20);
  rm.write(102, 30);

  auto result = rm.readBlock(100, 3);

  ASSERT_EQ(result.size(), 3);

  EXPECT_EQ(result[0], 10);
  EXPECT_EQ(result[1], 20);
  EXPECT_EQ(result[2], 30);
}

TEST(RegisterManager, ReadBlock_DefaultValue)
{
  RegisterManager rm;

  rm.write(100, 10);

  auto result = rm.readBlock(100, 3);

  EXPECT_EQ(result[0], 10);
  EXPECT_EQ(result[1], 0);
  EXPECT_EQ(result[2], 0);
}


TEST(RegisterManager, ReadBlock_Empty)
{
  RegisterManager rm;

  auto result = rm.readBlock(100, 0);

  EXPECT_EQ(result.size(), 0);
}