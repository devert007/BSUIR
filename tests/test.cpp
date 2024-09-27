#include "pch.h"
#include "D:/LABY/BSUIR/1labaPPOIS/Longint.h"
#include "D:/LABY/BSUIR/1labaPPOIS/Longint.cpp"
TEST(TestCaseConstructor1, defaultConstructor) {
	Longint a;
	a.setLong("123");
	EXPECT_EQ(a.getLong(), "123");
	EXPECT_TRUE(true);
}
TEST(TestCaseConstructor2, InitConstructor) {
	Longint a("-111");
	EXPECT_EQ(a.getLong(), "-111");
	EXPECT_TRUE(true);
}
TEST(TestCaseConstructor3, LongNumberConstructor) {
	Longint a("-22435678294652832222200000");
	EXPECT_EQ(a.getLong(), "-22435678294652832222200000");
	EXPECT_TRUE(true);
}


TEST(TestCaseSum, TestA_plus_B_Sum) {
	Longint a("22435670");
	Longint b("22435670");
	EXPECT_EQ("0", (a+b).getLong());
	EXPECT_TRUE(true);
}








int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}