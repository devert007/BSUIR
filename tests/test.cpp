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


TEST(TestCaseSum1, TestA_plus_B_Sum) {
	Longint a("22435670");
	Longint b("-22435670");
	EXPECT_EQ("-00000000", (a+b).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseSum2, TestA_plus_B_Sum) {
	Longint a("12345");
	Longint b("12345");
	EXPECT_EQ("24690", (a + b).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseSum3, TestA_plus_B_Sum) {
	Longint a("12345");
	Longint b("12345");
	EXPECT_EQ("24690", (a + b).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseSum4, TestA_plus_B_Sum) {
	Longint a("12345");
	EXPECT_EQ("24690", (a + 12345).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseSum5, TestA_plus_B_Sum) {
	Longint a("12345");
	EXPECT_EQ("24690", (a += 12345).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseSum6, TestA_plus_B_Sum) {
	Longint a("12345");
	Longint b("12345");
	EXPECT_EQ("24690", (a += b).getLong());
	EXPECT_TRUE(true);
}



TEST(TestCaseSub1, TestA_plus_B_Sub) {
	Longint a("22435670");
	Longint b("-22435670");
	EXPECT_EQ("44871340", (a - b).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseSub2, TestA_plus_B_Sub) {
	Longint a("12345");
	Longint b("12345");
	EXPECT_EQ("-00000", (a - b).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseSub3, TestA_plus_B_Sub) {
	Longint a("-12345");
	Longint b("12345");
	EXPECT_EQ("-24690", (a - b).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseSub4, TestA_plus_B_Sub) {
	Longint a("12345");
	EXPECT_EQ("-00000", (a - 12345).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseSub5, TestA_plus_B_Sub) {
	Longint a("12345");
	Longint b("12345");
	EXPECT_EQ("-00000", (a -= b).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseSub6, TestA_plus_B_Sub) {
	Longint a("12345");
	EXPECT_EQ("-00000", (a -= 12345).getLong());
	EXPECT_TRUE(true);
}


TEST(TestCaseMult1, TestA_mult_B_is) {
	Longint a("987654321");
	Longint b("987654321");
	EXPECT_EQ("975461057789971041", (a * b).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseMult2, TestA_mult_B_is) {
	Longint a("987654321");
	Longint b("-987654321");
	EXPECT_EQ("-975461057789971041", (a * b).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseMult3, TestA_mult_B_is) {
	Longint a("-987654321");
	Longint b("-987654321");
	EXPECT_EQ("975461057789971041", (a * b).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseMult4, TestA_mult_B_is) {
	Longint a("-987654321");
	EXPECT_EQ("-12192592592745", (a * 12345).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseMult5, TestA_mult_B_is) {
	Longint a("-987654321");
	Longint b("-987654321");
	b *= 12345;
	EXPECT_EQ(b.getLong(), (a *= 12345).getLong());
	EXPECT_TRUE(true);
}
TEST(TestCaseMult6, TestA_mult_B_is) {
	Longint a("-987654321");
	Longint b("-12345");
	EXPECT_EQ("12192592592745", (a *= b).getLong());
	EXPECT_TRUE(true);
}








int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}