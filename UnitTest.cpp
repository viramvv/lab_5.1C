#include <gtest/gtest.h>
#include "MoneyPublic.h"

TEST(MoneyTest, InitTest) {
    MoneyPublic m("10,50");
    EXPECT_EQ(m.getHryvnia(), 10);
    EXPECT_EQ(m.getKopeks(), 50);
}

TEST(MoneyTest, SubtractionException) {
    MoneyPublic m1(10, 0);
    MoneyPublic m2(20, 0);
    EXPECT_THROW(m1 - m2, MoneyException);
}

TEST(MoneyTest, Comparison) {
    MoneyPublic a(5, 0);
    MoneyPublic b(10, 0);
    EXPECT_TRUE(a < b);
    EXPECT_FALSE(a > b);
}