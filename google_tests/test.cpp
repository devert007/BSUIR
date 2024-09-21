#include "pch.h"
#include "D:/LABY/BSUIR/1laba/Longint.h"
#include "D:/LABY/BSUIR/1laba/Longint.cpp"
TEST(TestCaseConstructor1, TestConstructor) {
		Longint a("123");
		EXPECT_EQ(a.getLong(), "123");
		EXPECT_TRUE(true);
}
TEST(TestCaseConstructor2, TestConstructor2) {
	Longint a("-111");
	EXPECT_EQ(a.getLong(), "-111");
	EXPECT_TRUE(true);
}
TEST(TestCaseConstructor3, TestConstructor3) {
	Longint a("-22435678294652832222200000");
	EXPECT_EQ(a.getLong(), "-22435678294652832222200000");
	EXPECT_TRUE(true);
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}