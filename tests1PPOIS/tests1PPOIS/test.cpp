#include "pch.h"
#include "D:\LABY\BSUIR\tests1PPOIS\tests1PPOIS\Longint.cpp"
#include "D:\LABY\BSUIR\tests1PPOIS\tests1PPOIS\Longint.h"
#include "gtest/gtest.h"
TEST(TestCaseName, TestName) {
	Longint a("123");
  EXPECT_EQ(a.getLong(),"123");
  EXPECT_TRUE(true);
}