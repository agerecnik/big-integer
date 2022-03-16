#include <gtest/gtest.h>
#include "../src/big_integer.h"

TEST(big_integer_test, string_constructor)
{
    BigIntNS::BigInt bigInt1("-0385");
    BigIntNS::BigInt bigInt2("-00385");
    BigIntNS::BigInt bigInt3("-003805");
    BigIntNS::BigInt bigInt4("-0038050");
    BigIntNS::BigInt bigInt5("-3805");
    BigIntNS::BigInt bigInt6("-3850");
    BigIntNS::BigInt bigInt7("-385");
    BigIntNS::BigInt bigInt8("-000");
    BigIntNS::BigInt bigInt9("-0");

    BigIntNS::BigInt bigInt10("0385");
    BigIntNS::BigInt bigInt11("00385");
    BigIntNS::BigInt bigInt12("003805");
    BigIntNS::BigInt bigInt13("0038050");
    BigIntNS::BigInt bigInt14("3805");
    BigIntNS::BigInt bigInt15("3850");
    BigIntNS::BigInt bigInt16("385");
    BigIntNS::BigInt bigInt17("000");
    BigIntNS::BigInt bigInt18("0");

    std::stringstream ss;

    ss << bigInt1;
    EXPECT_EQ(ss.str(), "-385");

    ss.str(std::string());
    ss << bigInt2;
    EXPECT_EQ(ss.str(), "-385");

    ss.str(std::string());
    ss << bigInt3;
    EXPECT_EQ(ss.str(), "-3805");

    ss.str(std::string());
    ss << bigInt4;
    EXPECT_EQ(ss.str(), "-38050");

    ss.str(std::string());
    ss << bigInt5;
    EXPECT_EQ(ss.str(), "-3805");

    ss.str(std::string());
    ss << bigInt6;
    EXPECT_EQ(ss.str(), "-3850");

    ss.str(std::string());
    ss << bigInt7;
    EXPECT_EQ(ss.str(), "-385");

    ss.str(std::string());
    ss << bigInt8;
    EXPECT_EQ(ss.str(), "0");

    ss.str(std::string());
    ss << bigInt9;
    EXPECT_EQ(ss.str(), "0");

    ss.str(std::string());
    ss << bigInt10;
    EXPECT_EQ(ss.str(), "385");

    ss.str(std::string());
    ss << bigInt11;
    EXPECT_EQ(ss.str(), "385");

    ss.str(std::string());
    ss << bigInt12;
    EXPECT_EQ(ss.str(), "3805");

    ss.str(std::string());
    ss << bigInt13;
    EXPECT_EQ(ss.str(), "38050");

    ss.str(std::string());
    ss << bigInt14;
    EXPECT_EQ(ss.str(), "3805");

    ss.str(std::string());
    ss << bigInt15;
    EXPECT_EQ(ss.str(), "3850");

    ss.str(std::string());
    ss << bigInt16;
    EXPECT_EQ(ss.str(), "385");

    ss.str(std::string());
    ss << bigInt17;
    EXPECT_EQ(ss.str(), "0");

    ss.str(std::string());
    ss << bigInt18;
    EXPECT_EQ(ss.str(), "0");

    EXPECT_THROW(BigIntNS::BigInt("");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt("-");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt("--");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt("-a");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt("-3342a");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt("-334c2");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt("33-42");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt("3342-");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt("334c2");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt("c3342");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt("3342c");, std::invalid_argument);
}

TEST(big_integer_test, long_long_constructor)
{
    BigIntNS::BigInt bigInt1(-385);
    BigIntNS::BigInt bigInt2(0);
    BigIntNS::BigInt bigInt3(385);
    std::stringstream ss;

    ss << bigInt1;
    EXPECT_EQ(ss.str(), "-385");

    ss.str(std::string());
    ss << bigInt2;
    EXPECT_EQ(ss.str(), "0");

    ss.str(std::string());
    ss << bigInt3;
    EXPECT_EQ(ss.str(), "385");
}

TEST(big_integer_test, assignment_operator)
{
    BigIntNS::BigInt bigInt1(-200);
    BigIntNS::BigInt bigInt2(53);
    BigIntNS::BigInt bigInt3(-21);

    bigInt1 = bigInt2;
    EXPECT_EQ(bigInt1, bigInt2);

    bigInt1 += 1;
    EXPECT_EQ(bigInt1, BigIntNS::BigInt(54));
    EXPECT_EQ(bigInt2, BigIntNS::BigInt(53));

    bigInt1 = bigInt3;
    EXPECT_EQ(bigInt1, bigInt3);
}

TEST(big_integer_test, equality_operator)
{
    BigIntNS::BigInt bigInt1;
    BigIntNS::BigInt bigInt2;
    EXPECT_TRUE(bigInt1 == bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_TRUE(bigInt1 == bigInt2);

    bigInt1 = -50000000000000000;
    bigInt2 = -50000000000000000;
    EXPECT_TRUE(bigInt1 == bigInt2);

    bigInt1 = -50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_FALSE(bigInt1 == bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = -50000000000000000;
    EXPECT_FALSE(bigInt1 == bigInt2);

    bigInt1 = 0;
    bigInt2 = 0;
    EXPECT_TRUE(bigInt1 == bigInt2);

    bigInt1 = 1;
    bigInt2 = 0;
    EXPECT_FALSE(bigInt1 == bigInt2);

    bigInt1 = 0;
    bigInt2 = 1;
    EXPECT_FALSE(bigInt1 == bigInt2);

    bigInt1 = -1;
    bigInt2 = 0;
    EXPECT_FALSE(bigInt1 == bigInt2);

    bigInt1 = 0;
    bigInt2 = -1;
    EXPECT_FALSE(bigInt1 == bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 == bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 == bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 == bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 == bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    EXPECT_FALSE(bigInt1 == bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 == bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    EXPECT_FALSE(bigInt1 == bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 == bigInt2);
}

TEST(big_integer_test, inequality_operator)
{
    BigIntNS::BigInt bigInt1;
    BigIntNS::BigInt bigInt2;
    EXPECT_FALSE(bigInt1 != bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_FALSE(bigInt1 != bigInt2);

    bigInt1 = -50000000000000000;
    bigInt2 = -50000000000000000;
    EXPECT_FALSE(bigInt1 != bigInt2);

    bigInt1 = -50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_TRUE(bigInt1 != bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = -50000000000000000;
    EXPECT_TRUE(bigInt1 != bigInt2);

    bigInt1 = 0;
    bigInt2 = 0;
    EXPECT_FALSE(bigInt1 != bigInt2);

    bigInt1 = 1;
    bigInt2 = 0;
    EXPECT_TRUE(bigInt1 != bigInt2);

    bigInt1 = 0;
    bigInt2 = 1;
    EXPECT_TRUE(bigInt1 != bigInt2);

    bigInt1 = -1;
    bigInt2 = 0;
    EXPECT_TRUE(bigInt1 != bigInt2);

    bigInt1 = 0;
    bigInt2 = -1;
    EXPECT_TRUE(bigInt1 != bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 != bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 != bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 != bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 != bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    EXPECT_TRUE(bigInt1 != bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 != bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    EXPECT_TRUE(bigInt1 != bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 != bigInt2);
}

TEST(big_integer_test, less_than_operator)
{
    BigIntNS::BigInt bigInt1;
    BigIntNS::BigInt bigInt2;
    EXPECT_FALSE(bigInt1 < bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_FALSE(bigInt1 < bigInt2);

    bigInt1 = -50000000000000000;
    bigInt2 = -50000000000000000;
    EXPECT_FALSE(bigInt1 < bigInt2);

    bigInt1 = -50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_TRUE(bigInt1 < bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = -50000000000000000;
    EXPECT_FALSE(bigInt1 < bigInt2);

    bigInt1 = 0;
    bigInt2 = 0;
    EXPECT_FALSE(bigInt1 < bigInt2);

    bigInt1 = 1;
    bigInt2 = 0;
    EXPECT_FALSE(bigInt1 < bigInt2);

    bigInt1 = 0;
    bigInt2 = 1;
    EXPECT_TRUE(bigInt1 < bigInt2);

    bigInt1 = -1;
    bigInt2 = 0;
    EXPECT_TRUE(bigInt1 < bigInt2);

    bigInt1 = 0;
    bigInt2 = -1;
    EXPECT_FALSE(bigInt1 < bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 < bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 < bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 < bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 < bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    EXPECT_FALSE(bigInt1 < bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 < bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    EXPECT_TRUE(bigInt1 < bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 < bigInt2);
}

TEST(big_integer_test, less_than_or_equal_operator)
{
    BigIntNS::BigInt bigInt1;
    BigIntNS::BigInt bigInt2;
    EXPECT_TRUE(bigInt1 <= bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_TRUE(bigInt1 <= bigInt2);

    bigInt1 = -50000000000000000;
    bigInt2 = -50000000000000000;
    EXPECT_TRUE(bigInt1 <= bigInt2);

    bigInt1 = -50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_TRUE(bigInt1 <= bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = -50000000000000000;
    EXPECT_FALSE(bigInt1 <= bigInt2);

    bigInt1 = 0;
    bigInt2 = 0;
    EXPECT_TRUE(bigInt1 <= bigInt2);

    bigInt1 = 1;
    bigInt2 = 0;
    EXPECT_FALSE(bigInt1 <= bigInt2);

    bigInt1 = 0;
    bigInt2 = 1;
    EXPECT_TRUE(bigInt1 <= bigInt2);

    bigInt1 = -1;
    bigInt2 = 0;
    EXPECT_TRUE(bigInt1 <= bigInt2);

    bigInt1 = 0;
    bigInt2 = -1;
    EXPECT_FALSE(bigInt1 <= bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 <= bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 <= bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 <= bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 <= bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    EXPECT_FALSE(bigInt1 <= bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 <= bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    EXPECT_TRUE(bigInt1 <= bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 <= bigInt2);
}

TEST(big_integer_test, more_than_operator)
{
    BigIntNS::BigInt bigInt1;
    BigIntNS::BigInt bigInt2;
    EXPECT_FALSE(bigInt1 > bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_FALSE(bigInt1 > bigInt2);

    bigInt1 = -50000000000000000;
    bigInt2 = -50000000000000000;
    EXPECT_FALSE(bigInt1 > bigInt2);

    bigInt1 = -50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_FALSE(bigInt1 > bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = -50000000000000000;
    EXPECT_TRUE(bigInt1 > bigInt2);

    bigInt1 = 0;
    bigInt2 = 0;
    EXPECT_FALSE(bigInt1 > bigInt2);

    bigInt1 = 1;
    bigInt2 = 0;
    EXPECT_TRUE(bigInt1 > bigInt2);

    bigInt1 = 0;
    bigInt2 = 1;
    EXPECT_FALSE(bigInt1 > bigInt2);

    bigInt1 = -1;
    bigInt2 = 0;
    EXPECT_FALSE(bigInt1 > bigInt2);

    bigInt1 = 0;
    bigInt2 = -1;
    EXPECT_TRUE(bigInt1 > bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 > bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 > bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 > bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 > bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    EXPECT_TRUE(bigInt1 > bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 > bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    EXPECT_FALSE(bigInt1 > bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 > bigInt2);
}

TEST(big_integer_test, more_than_or_equal_operator)
{
    BigIntNS::BigInt bigInt1;
    BigIntNS::BigInt bigInt2;
    EXPECT_TRUE(bigInt1 >= bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_TRUE(bigInt1 >= bigInt2);

    bigInt1 = -50000000000000000;
    bigInt2 = -50000000000000000;
    EXPECT_TRUE(bigInt1 >= bigInt2);

    bigInt1 = -50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_FALSE(bigInt1 >= bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = -50000000000000000;
    EXPECT_TRUE(bigInt1 >= bigInt2);

    bigInt1 = 0;
    bigInt2 = 0;
    EXPECT_TRUE(bigInt1 >= bigInt2);

    bigInt1 = 1;
    bigInt2 = 0;
    EXPECT_TRUE(bigInt1 >= bigInt2);

    bigInt1 = 0;
    bigInt2 = 1;
    EXPECT_FALSE(bigInt1 >= bigInt2);

    bigInt1 = -1;
    bigInt2 = 0;
    EXPECT_FALSE(bigInt1 >= bigInt2);

    bigInt1 = 0;
    bigInt2 = -1;
    EXPECT_TRUE(bigInt1 >= bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 >= bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 >= bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 >= bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 >= bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    EXPECT_TRUE(bigInt1 >= bigInt2);

    bigInt1 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    bigInt2 = std::string("454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_FALSE(bigInt1 >= bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    EXPECT_FALSE(bigInt1 >= bigInt2);

    bigInt1 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476882");
    bigInt2 = std::string("-454649349994364999769303767499999999999346436436363699923439"
                          "992342324375786948476883");
    EXPECT_TRUE(bigInt1 >= bigInt2);
}

TEST(big_integer_test, compund_assignment_plus_operator)
{
    BigIntNS::BigInt bigInt;
    BigIntNS::BigInt refBigInt;

    // NEGATIVE += NEGATIVE
    // higer += lower
    bigInt = -20;
    bigInt += -983;
    refBigInt = -1003;
    EXPECT_EQ(bigInt, refBigInt);

    // lower += higher
    bigInt = -983;
    bigInt += -20;
    refBigInt = -1003;
    EXPECT_EQ(bigInt, refBigInt);

    // equal
    bigInt = -50;
    bigInt += -50;
    refBigInt = -100;
    EXPECT_EQ(bigInt, refBigInt);


    // NEGATIVE += POSITIVE
    // stay negative
    bigInt = -1225;
    bigInt += 1217;
    refBigInt = -8;
    EXPECT_EQ(bigInt, refBigInt);

    // become positive
    bigInt = -1225;
    bigInt += 1233;
    refBigInt = 8;
    EXPECT_EQ(bigInt, refBigInt);

    // become zero
    bigInt = -1225;
    bigInt += 1225;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);


    // POSITIVE += NEGATIVE
    // stay positive
    bigInt = 1225;
    bigInt += -1217;
    refBigInt = 8;
    EXPECT_EQ(bigInt, refBigInt);

    // become negative
    bigInt = 1225;
    bigInt += -1233;
    refBigInt = -8;
    EXPECT_EQ(bigInt, refBigInt);

    // become zero
    bigInt = 1225;
    bigInt += -1225;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);


    // POSITIVE += POSITIVE
    // higer += lower
    bigInt = 983;
    bigInt += 20;
    refBigInt = 1003;
    EXPECT_EQ(bigInt, refBigInt);

    // lower += higher
    bigInt = 20;
    bigInt += 983;
    refBigInt = 1003;
    EXPECT_EQ(bigInt, refBigInt);

    // equal
    bigInt = 50;
    bigInt += 50;
    refBigInt = 100;
    EXPECT_EQ(bigInt, refBigInt);


    // ZERO += POSITIVE
    bigInt = 0;
    bigInt += 267;
    refBigInt = 267;
    EXPECT_EQ(bigInt, refBigInt);

    // POSITIVE += ZERO
    bigInt = 267;
    bigInt += 0;
    refBigInt = 267;
    EXPECT_EQ(bigInt, refBigInt);

    // ZERO += NEGATIVE
    bigInt = 0;
    bigInt += -267;
    refBigInt = -267;
    EXPECT_EQ(bigInt, refBigInt);

    // NEGATIVE += ZERO
    bigInt = -267;
    bigInt += 0;
    refBigInt = -267;
    EXPECT_EQ(bigInt, refBigInt);


    // BIG NUMBER
    bigInt = std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                         "9999999999999937");
    bigInt += std::string("63");
    refBigInt = std::string("10000000000000000000000000000000000000000000000000000000000000000"
                            "00000000000000000000");
    EXPECT_EQ(bigInt, refBigInt);
}

TEST(big_integer_test, compund_assignment_minus_operator)
{
    BigIntNS::BigInt bigInt;
    BigIntNS::BigInt refBigInt;

    // NEGATIVE -= NEGATIVE
    bigInt = -1225;
    bigInt -= -1217;
    refBigInt = -8;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -1225;
    bigInt -= -1233;
    refBigInt = 8;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -500;
    bigInt -= -500;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);


    // NEGATIVE -= POSITIVE
    bigInt = -20;
    bigInt -= 983;
    refBigInt = -1003;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -983;
    bigInt -= 20;
    refBigInt = -1003;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -50;
    bigInt -= 50;
    refBigInt = -100;
    EXPECT_EQ(bigInt, refBigInt);


    // POSITIVE -= NEGATIVE
    bigInt = 20;
    bigInt -= -983;
    refBigInt = 1003;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 983;
    bigInt -= -20;
    refBigInt = 1003;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 50;
    bigInt -= -50;
    refBigInt = 100;
    EXPECT_EQ(bigInt, refBigInt);


    // POSITIVE -= POSITIVE
    bigInt = 1225;
    bigInt -= 1217;
    refBigInt = 8;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 1225;
    bigInt -= 1233;
    refBigInt = -8;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 500;
    bigInt -= 500;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);


    // ZERO -= POSITIVE
    bigInt = 0;
    bigInt -= 267;
    refBigInt = -267;
    EXPECT_EQ(bigInt, refBigInt);

    // POSITIVE -= ZERO
    bigInt = 267;
    bigInt -= 0;
    refBigInt = 267;
    EXPECT_EQ(bigInt, refBigInt);

    // ZERO -= NEGATIVE
    bigInt = 0;
    bigInt -= -267;
    refBigInt = 267;
    EXPECT_EQ(bigInt, refBigInt);

    // NEGATIVE -= ZERO
    bigInt = -267;
    bigInt -= 0;
    refBigInt = -267;
    EXPECT_EQ(bigInt, refBigInt);


    // BIG NUMBER
    bigInt = std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                         "9999999999999937");
    bigInt -= std::string("-63");
    refBigInt = std::string("10000000000000000000000000000000000000000000000000000000000000000"
                            "00000000000000000000");
    EXPECT_EQ(bigInt, refBigInt);
}

TEST(big_integer_test, compund_assignment_multiplication_operator)
{
    BigIntNS::BigInt bigInt;
    BigIntNS::BigInt refBigInt;

    // POSITIVE *= POSITIVE
    bigInt = 3840;
    bigInt *= 571;
    refBigInt = 2192640;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 571;
    bigInt *= 3840;
    refBigInt = 2192640;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 1;
    bigInt *= 783195;
    refBigInt = 783195;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 783195;
    bigInt *= 1;
    refBigInt = 783195;
    EXPECT_EQ(bigInt, refBigInt);

    // POSITIVE *= NEGATIVE
    bigInt = 3840;
    bigInt *= -571;
    refBigInt = -2192640;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 571;
    bigInt *= -3840;
    refBigInt = -2192640;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 1;
    bigInt *= -783195;
    refBigInt = -783195;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 783195;
    bigInt *= -1;
    refBigInt = -783195;
    EXPECT_EQ(bigInt, refBigInt);

    // NEGATIVE *= POSITIVE
    bigInt = -3840;
    bigInt *= 571;
    refBigInt = -2192640;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -571;
    bigInt *= 3840;
    refBigInt = -2192640;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -1;
    bigInt *= 783195;
    refBigInt = -783195;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -783195;
    bigInt *= 1;
    refBigInt = -783195;
    EXPECT_EQ(bigInt, refBigInt);

    // NEGATIVE *= NEGATIVE
    bigInt = -3840;
    bigInt *= -571;
    refBigInt = 2192640;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -571;
    bigInt *= -3840;
    refBigInt = 2192640;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -1;
    bigInt *= -783195;
    refBigInt = 783195;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -783195;
    bigInt *= -1;
    refBigInt = 783195;
    EXPECT_EQ(bigInt, refBigInt);

    // ZERO
    bigInt = 0;
    bigInt *= 3840;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 0;
    bigInt *= -3840;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 3840;
    bigInt *= 0;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -3840;
    bigInt *= 0;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    // BIG NUMBER
    bigInt = std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                         "9999999999999937");
    bigInt *= std::string("10");
    refBigInt =
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "99999999999999370");
    EXPECT_EQ(bigInt, refBigInt);
}

TEST(big_integer_test, compund_assignment_division_operator)
{
    BigIntNS::BigInt bigInt;
    BigIntNS::BigInt refBigInt;

    // POSITIVE /= POSITIVE
    bigInt = 571;
    bigInt /= 572;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 572;
    bigInt /= 571;
    refBigInt = 1;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 3840;
    bigInt /= 571;
    refBigInt = 6;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 3840;
    bigInt /= 1;
    refBigInt = 3840;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 571;
    bigInt /= 3840;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 84;
    bigInt /= 84;
    refBigInt = 1;
    EXPECT_EQ(bigInt, refBigInt);

    // POSITIVE /= NEGATIVE
    bigInt = 571;
    bigInt /= -572;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 572;
    bigInt /= -571;
    refBigInt = -1;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 3840;
    bigInt /= -571;
    refBigInt = -6;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 3840;
    bigInt /= -1;
    refBigInt = -3840;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 571;
    bigInt /= -3840;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 84;
    bigInt /= -84;
    refBigInt = -1;
    EXPECT_EQ(bigInt, refBigInt);

    // NEGATIVE /= POSITIVE
    bigInt = -571;
    bigInt /= 572;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -572;
    bigInt /= 571;
    refBigInt = -1;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -3840;
    bigInt /= 571;
    refBigInt = -6;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -3840;
    bigInt /= 1;
    refBigInt = -3840;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -571;
    bigInt /= 3840;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -84;
    bigInt /= 84;
    refBigInt = -1;
    EXPECT_EQ(bigInt, refBigInt);

    // NEGATIVE /= NEGATIVE
    bigInt = -571;
    bigInt /= -572;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -572;
    bigInt /= -571;
    refBigInt = 1;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -3840;
    bigInt /= -571;
    refBigInt = 6;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -3840;
    bigInt /= -1;
    refBigInt = 3840;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -571;
    bigInt /= -3840;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -84;
    bigInt /= -84;
    refBigInt = 1;
    EXPECT_EQ(bigInt, refBigInt);

    // ZERO
    bigInt = 0;
    bigInt /= 3840;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 0;
    bigInt /= -3840;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 3840;
    EXPECT_THROW(bigInt /= 0, std::invalid_argument);

    bigInt = -3840;
    EXPECT_THROW(bigInt /= 0, std::invalid_argument);

    bigInt = 0;
    EXPECT_THROW(bigInt /= 0, std::invalid_argument);

    // BIG NUMBER
    bigInt = std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                         "9999999999999937");
    bigInt /= std::string("10");
    refBigInt =
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "999999999999993");
    EXPECT_EQ(bigInt, refBigInt);
}

TEST(big_integer_test, compund_assignment_modulo_operator)
{
    BigIntNS::BigInt bigInt;
    BigIntNS::BigInt refBigInt;

    // POSITIVE %= POSITIVE
    bigInt = 571;
    bigInt %= 572;
    refBigInt = 571;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 572;
    bigInt %= 571;
    refBigInt = 1;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 3840;
    bigInt %= 571;
    refBigInt = 414;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 3840;
    bigInt %= 1;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 571;
    bigInt %= 3840;
    refBigInt = 571;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 84;
    bigInt %= 84;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    // POSITIVE %= NEGATIVE
    bigInt = 571;
    bigInt %= -572;
    refBigInt = 571;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 572;
    bigInt %= -571;
    refBigInt = 1;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 3840;
    bigInt %= -571;
    refBigInt = 414;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 3840;
    bigInt %= -1;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 571;
    bigInt %= -3840;
    refBigInt = 571;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 84;
    bigInt %= -84;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    // NEGATIVE %= POSITIVE
    bigInt = -571;
    bigInt %= 572;
    refBigInt = -571;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -572;
    bigInt %= 571;
    refBigInt = -1;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -3840;
    bigInt %= 571;
    refBigInt = -414;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -3840;
    bigInt %= 1;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -571;
    bigInt %= 3840;
    refBigInt = -571;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -84;
    bigInt %= 84;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    // NEGATIVE %= NEGATIVE
    bigInt = -571;
    bigInt %= -572;
    refBigInt = -571;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -572;
    bigInt %= -571;
    refBigInt = -1;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -3840;
    bigInt %= -571;
    refBigInt = -414;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -3840;
    bigInt %= -1;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -571;
    bigInt %= -3840;
    refBigInt = -571;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = -84;
    bigInt %= -84;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    // ZERO
    bigInt = 0;
    bigInt %= 3840;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 0;
    bigInt %= -3840;
    refBigInt = 0;
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = 3840;
    EXPECT_THROW(bigInt %= 0, std::invalid_argument);

    bigInt = -3840;
    EXPECT_THROW(bigInt %= 0, std::invalid_argument);

    bigInt = 0;
    EXPECT_THROW(bigInt %= 0, std::invalid_argument);

    // BIG NUMBER
    bigInt = std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                         "9999999999999937");
    bigInt %= std::string("10");
    refBigInt = std::string("7");
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                         "9999999999999937");
    bigInt %=
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "99999999999999377");
    refBigInt =
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "9999999999999937");
    EXPECT_EQ(bigInt, refBigInt);
}

TEST(big_integer_test, increment_prefix_operator)
{
    BigIntNS::BigInt bigInt = -5;
    BigIntNS::BigInt refBigInt = 5;
    BigIntNS::BigInt tempBigInt;
    for (size_t i = 0; i < 10; ++i) {
        tempBigInt = ++bigInt;
    }
    EXPECT_EQ(bigInt, tempBigInt);
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                         "9999999999999995");
    refBigInt = std::string("10000000000000000000000000000000000000000000000000000000000000000"
                            "00000000000000000005");
    for (size_t i = 0; i < 10; ++i) {
        tempBigInt = ++bigInt;
    }
    EXPECT_EQ(bigInt, tempBigInt);
    EXPECT_EQ(bigInt, refBigInt);
}

TEST(big_integer_test, increment_postfix_operator)
{
    BigIntNS::BigInt bigInt = -5;
    BigIntNS::BigInt refBigInt = 5;
    BigIntNS::BigInt tempBigInt;
    for (size_t i = 0; i < 10; ++i) {
        tempBigInt = bigInt++;
    }
    tempBigInt += 1;
    EXPECT_EQ(bigInt, tempBigInt);
    EXPECT_EQ(bigInt, refBigInt);


    bigInt = std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                         "9999999999999995");
    refBigInt = std::string("10000000000000000000000000000000000000000000000000000000000000000"
                            "00000000000000000005");
    for (size_t i = 0; i < 10; ++i) {
        tempBigInt = bigInt++;
    }
    tempBigInt += 1;
    EXPECT_EQ(bigInt, tempBigInt);
    EXPECT_EQ(bigInt, refBigInt);
}

TEST(big_integer_test, decrement_prefix_operator)
{
    BigIntNS::BigInt bigInt = 5;
    BigIntNS::BigInt refBigInt = -5;
    BigIntNS::BigInt tempBigInt;
    for (size_t i = 0; i < 10; ++i) {
        tempBigInt = --bigInt;
    }
    EXPECT_EQ(bigInt, tempBigInt);
    EXPECT_EQ(bigInt, refBigInt);

    bigInt = std::string("10000000000000000000000000000000000000000000000000000000000000000"
                         "00000000000000000005");
    refBigInt =
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "9999999999999995");
    for (size_t i = 0; i < 10; ++i) {
        tempBigInt = --bigInt;
    }
    EXPECT_EQ(bigInt, tempBigInt);
    EXPECT_EQ(bigInt, refBigInt);
}

TEST(big_integer_test, decrement_postfix_operator)
{
    BigIntNS::BigInt bigInt = 5;
    BigIntNS::BigInt refBigInt = -5;
    BigIntNS::BigInt tempBigInt;
    for (size_t i = 0; i < 10; ++i) {
        tempBigInt = bigInt--;
    }
    tempBigInt -= 1;
    EXPECT_EQ(bigInt, tempBigInt);
    EXPECT_EQ(bigInt, refBigInt);


    bigInt = std::string("10000000000000000000000000000000000000000000000000000000000000000"
                         "00000000000000000005");
    refBigInt =
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "9999999999999995");
    for (size_t i = 0; i < 10; ++i) {
        tempBigInt = bigInt--;
    }
    tempBigInt -= 1;
    EXPECT_EQ(bigInt, tempBigInt);
    EXPECT_EQ(bigInt, refBigInt);
}

TEST(big_integer_test, plus_operator)
{
    BigIntNS::BigInt bigInt;
    BigIntNS::BigInt refBigInt;
    BigIntNS::BigInt tempBigInt;

    // NEGATIVE + NEGATIVE
    // higer + lower
    bigInt = -20;
    tempBigInt = bigInt + (-983);
    refBigInt = -1003;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -20);

    // lower + higher
    bigInt = -983;
    tempBigInt = bigInt + (-20);
    refBigInt = -1003;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -983);

    // equal
    bigInt = -50;
    tempBigInt = bigInt + (-50);
    refBigInt = -100;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -50);


    // NEGATIVE + POSITIVE
    // stay negative
    bigInt = -1225;
    tempBigInt = bigInt + 1217;
    refBigInt = -8;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -1225);

    // become positive
    bigInt = -1225;
    tempBigInt = bigInt + 1233;
    refBigInt = 8;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -1225);

    // become zero
    bigInt = -1225;
    tempBigInt = bigInt + 1225;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -1225);


    // POSITIVE + NEGATIVE
    // stay positive
    bigInt = 1225;
    tempBigInt = bigInt + (-1217);
    refBigInt = 8;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 1225);

    // become negative
    bigInt = 1225;
    tempBigInt = bigInt + (-1233);
    refBigInt = -8;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 1225);

    // become zero
    bigInt = 1225;
    tempBigInt = bigInt + (-1225);
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 1225);


    // POSITIVE + POSITIVE
    // higer + lower
    bigInt = 983;
    tempBigInt = bigInt + 20;
    refBigInt = 1003;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 983);

    // lower + higher
    bigInt = 20;
    tempBigInt = bigInt + 983;
    refBigInt = 1003;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 20);

    // equal
    bigInt = 50;
    tempBigInt = bigInt + 50;
    refBigInt = 100;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 50);


    // ZERO + POSITIVE
    bigInt = 0;
    tempBigInt = bigInt + 267;
    refBigInt = 267;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 0);

    // POSITIVE + ZERO
    bigInt = 267;
    tempBigInt = bigInt + 0;
    refBigInt = 267;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 267);

    // ZERO + NEGATIVE
    bigInt = 0;
    tempBigInt = bigInt + (-267);
    refBigInt = -267;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 0);

    // NEGATIVE + ZERO
    bigInt = -267;
    tempBigInt = bigInt + 0;
    refBigInt = -267;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -267);


    // BIG NUMBER
    bigInt = std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                         "9999999999999937");
    tempBigInt = bigInt + std::string("63");
    refBigInt = std::string("10000000000000000000000000000000000000000000000000000000000000000"
                            "00000000000000000000");
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(
        bigInt,
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "9999999999999937"));
}

TEST(big_integer_test, minus_operator)
{
    BigIntNS::BigInt bigInt;
    BigIntNS::BigInt refBigInt;
    BigIntNS::BigInt tempBigInt;

    // NEGATIVE - NEGATIVE
    bigInt = -1225;
    tempBigInt = bigInt - (-1217);
    refBigInt = -8;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -1225);

    bigInt = -1225;
    tempBigInt = bigInt - (-1233);
    refBigInt = 8;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -1225);

    bigInt = -500;
    tempBigInt = bigInt - (-500);
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -500);


    // NEGATIVE - POSITIVE
    bigInt = -20;
    tempBigInt = bigInt - 983;
    refBigInt = -1003;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -20);

    bigInt = -983;
    tempBigInt = bigInt - 20;
    refBigInt = -1003;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -983);

    bigInt = -50;
    tempBigInt = bigInt - 50;
    refBigInt = -100;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -50);


    // POSITIVE - NEGATIVE
    bigInt = 20;
    tempBigInt = bigInt - (-983);
    refBigInt = 1003;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 20);

    bigInt = 983;
    tempBigInt = bigInt - (-20);
    refBigInt = 1003;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 983);

    bigInt = 50;
    tempBigInt = bigInt - (-50);
    refBigInt = 100;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 50);


    // POSITIVE - POSITIVE
    bigInt = 1225;
    tempBigInt = bigInt - 1217;
    refBigInt = 8;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 1225);

    bigInt = 1225;
    tempBigInt = bigInt - 1233;
    refBigInt = -8;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 1225);

    bigInt = 500;
    tempBigInt = bigInt - 500;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 500);


    // ZERO - POSITIVE
    bigInt = 0;
    tempBigInt = bigInt - 267;
    refBigInt = -267;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 0);

    // POSITIVE - ZERO
    bigInt = 267;
    tempBigInt = bigInt - 0;
    refBigInt = 267;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 267);

    // ZERO - NEGATIVE
    bigInt = 0;
    tempBigInt = bigInt - (-267);
    refBigInt = 267;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 0);

    // NEGATIVE - ZERO
    bigInt = -267;
    tempBigInt = bigInt - 0;
    refBigInt = -267;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -267);


    // BIG NUMBER
    bigInt = std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                         "9999999999999937");
    tempBigInt = bigInt - std::string("-63");
    refBigInt = std::string("10000000000000000000000000000000000000000000000000000000000000000"
                            "00000000000000000000");
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(
        bigInt,
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "9999999999999937"));
}

TEST(big_integer_test, multiplication_operator)
{
    BigIntNS::BigInt bigInt;
    BigIntNS::BigInt refBigInt;
    BigIntNS::BigInt tempBigInt;

    // POSITIVE * POSITIVE
    bigInt = 3840;
    tempBigInt = bigInt * 571;
    refBigInt = 2192640;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 3840);

    bigInt = 571;
    tempBigInt = bigInt * 3840;
    refBigInt = 2192640;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 571);

    bigInt = 1;
    tempBigInt = bigInt * 783195;
    refBigInt = 783195;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 1);

    bigInt = 783195;
    tempBigInt = bigInt * 1;
    refBigInt = 783195;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 783195);

    // POSITIVE * NEGATIVE
    bigInt = 3840;
    tempBigInt = bigInt * (-571);
    refBigInt = -2192640;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 3840);

    bigInt = 571;
    tempBigInt = bigInt * (-3840);
    refBigInt = -2192640;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 571);

    bigInt = 1;
    tempBigInt = bigInt * (-783195);
    refBigInt = -783195;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 1);

    bigInt = 783195;
    tempBigInt = bigInt * (-1);
    refBigInt = -783195;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 783195);

    // NEGATIVE * POSITIVE
    bigInt = -3840;
    tempBigInt = bigInt * 571;
    refBigInt = -2192640;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -3840);

    bigInt = -571;
    tempBigInt = bigInt * 3840;
    refBigInt = -2192640;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -571);

    bigInt = -1;
    tempBigInt = bigInt * 783195;
    refBigInt = -783195;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -1);

    bigInt = -783195;
    tempBigInt = bigInt * 1;
    refBigInt = -783195;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -783195);

    // NEGATIVE * NEGATIVE
    bigInt = -3840;
    tempBigInt = bigInt * (-571);
    refBigInt = 2192640;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -3840);

    bigInt = -571;
    tempBigInt = bigInt * (-3840);
    refBigInt = 2192640;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -571);

    bigInt = -1;
    tempBigInt = bigInt * (-783195);
    refBigInt = 783195;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -1);

    bigInt = -783195;
    tempBigInt = bigInt * (-1);
    refBigInt = 783195;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -783195);

    // ZERO
    bigInt = 0;
    tempBigInt = bigInt * 3840;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 0);

    bigInt = 0;
    tempBigInt = bigInt * (-3840);
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 0);

    bigInt = 3840;
    tempBigInt = bigInt * 0;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 3840);

    bigInt = -3840;
    tempBigInt = bigInt * 0;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -3840);

    // BIG NUMBER
    bigInt = std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                         "9999999999999937");
    tempBigInt = bigInt * std::string("10");
    refBigInt =
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "99999999999999370");
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(
        bigInt,
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "9999999999999937"));
}

TEST(big_integer_test, division_operator)
{
    BigIntNS::BigInt bigInt;
    BigIntNS::BigInt refBigInt;
    BigIntNS::BigInt tempBigInt;

    // POSITIVE / POSITIVE
    bigInt = 571;
    tempBigInt = bigInt / 572;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 571);

    bigInt = 572;
    tempBigInt = bigInt / 571;
    refBigInt = 1;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 572);

    bigInt = 3840;
    tempBigInt = bigInt / 571;
    refBigInt = 6;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 3840);

    bigInt = 3840;
    tempBigInt = bigInt / 1;
    refBigInt = 3840;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 3840);

    bigInt = 571;
    tempBigInt = bigInt / 3840;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 571);

    bigInt = 84;
    tempBigInt = bigInt / 84;
    refBigInt = 1;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 84);

    // POSITIVE / NEGATIVE
    bigInt = 571;
    tempBigInt = bigInt / (-572);
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 571);

    bigInt = 572;
    tempBigInt = bigInt / (-571);
    refBigInt = -1;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 572);

    bigInt = 3840;
    tempBigInt = bigInt / (-571);
    refBigInt = -6;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 3840);

    bigInt = 3840;
    tempBigInt = bigInt / (-1);
    refBigInt = -3840;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 3840);

    bigInt = 571;
    tempBigInt = bigInt / (-3840);
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 571);

    bigInt = 84;
    tempBigInt = bigInt / (-84);
    refBigInt = -1;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 84);

    // NEGATIVE / POSITIVE
    bigInt = -571;
    tempBigInt = bigInt / 572;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -571);

    bigInt = -572;
    tempBigInt = bigInt / 571;
    refBigInt = -1;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -572);

    bigInt = -3840;
    tempBigInt = bigInt / 571;
    refBigInt = -6;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -3840);

    bigInt = -3840;
    tempBigInt = bigInt / 1;
    refBigInt = -3840;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -3840);

    bigInt = -571;
    tempBigInt = bigInt / 3840;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -571);

    bigInt = -84;
    tempBigInt = bigInt / 84;
    refBigInt = -1;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -84);

    // NEGATIVE / NEGATIVE
    bigInt = -571;
    tempBigInt = bigInt / (-572);
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -571);

    bigInt = -572;
    tempBigInt = bigInt / (-571);
    refBigInt = 1;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -572);

    bigInt = -3840;
    tempBigInt = bigInt / (-571);
    refBigInt = 6;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -3840);

    bigInt = -3840;
    tempBigInt = bigInt / (-1);
    refBigInt = 3840;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -3840);

    bigInt = -571;
    tempBigInt = bigInt / (-3840);
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -571);

    bigInt = -84;
    tempBigInt = bigInt / (-84);
    refBigInt = 1;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -84);

    // ZERO
    bigInt = 0;
    tempBigInt = bigInt / 3840;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 0);

    bigInt = 0;
    tempBigInt = bigInt / (-3840);
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 0);

    bigInt = 3840;
    EXPECT_THROW(bigInt / 0, std::invalid_argument);

    bigInt = -3840;
    EXPECT_THROW(bigInt / 0, std::invalid_argument);

    bigInt = 0;
    EXPECT_THROW(bigInt / 0, std::invalid_argument);

    // BIG NUMBER
    bigInt = std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                         "9999999999999937");
    tempBigInt = bigInt / std::string("10");
    refBigInt =
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "999999999999993");
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(
        bigInt,
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "9999999999999937"));
}

TEST(big_integer_test, modulo_operator)
{
    BigIntNS::BigInt bigInt;
    BigIntNS::BigInt refBigInt;
    BigIntNS::BigInt tempBigInt;

    // POSITIVE % POSITIVE
    bigInt = 571;
    tempBigInt = bigInt % 572;
    refBigInt = 571;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 571);

    bigInt = 572;
    tempBigInt = bigInt % 571;
    refBigInt = 1;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 572);

    bigInt = 3840;
    tempBigInt = bigInt % 571;
    refBigInt = 414;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 3840);

    bigInt = 3840;
    tempBigInt = bigInt % 1;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 3840);

    bigInt = 571;
    tempBigInt = bigInt % 3840;
    refBigInt = 571;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 571);

    bigInt = 84;
    tempBigInt = bigInt % 84;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 84);

    // POSITIVE % NEGATIVE
    bigInt = 571;
    tempBigInt = bigInt % (-572);
    refBigInt = 571;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 571);

    bigInt = 572;
    tempBigInt = bigInt % (-571);
    refBigInt = 1;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 572);

    bigInt = 3840;
    tempBigInt = bigInt % (-571);
    refBigInt = 414;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 3840);

    bigInt = 3840;
    tempBigInt = bigInt % (-1);
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 3840);

    bigInt = 571;
    tempBigInt = bigInt % (-3840);
    refBigInt = 571;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 571);

    bigInt = 84;
    tempBigInt = bigInt % (-84);
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 84);

    // NEGATIVE % POSITIVE
    bigInt = -571;
    tempBigInt = bigInt % 572;
    refBigInt = -571;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -571);

    bigInt = -572;
    tempBigInt = bigInt % 571;
    refBigInt = -1;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -572);

    bigInt = -3840;
    tempBigInt = bigInt % 571;
    refBigInt = -414;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -3840);

    bigInt = -3840;
    tempBigInt = bigInt % 1;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -3840);

    bigInt = -571;
    tempBigInt = bigInt % 3840;
    refBigInt = -571;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -571);

    bigInt = -84;
    tempBigInt = bigInt % 84;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -84);

    // NEGATIVE % NEGATIVE
    bigInt = -571;
    tempBigInt = bigInt % (-572);
    refBigInt = -571;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -571);

    bigInt = -572;
    tempBigInt = bigInt % (-571);
    refBigInt = -1;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -572);

    bigInt = -3840;
    tempBigInt = bigInt % (-571);
    refBigInt = -414;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -3840);

    bigInt = -3840;
    tempBigInt = bigInt % (-1);
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -3840);

    bigInt = -571;
    tempBigInt = bigInt % (-3840);
    refBigInt = -571;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -571);

    bigInt = -84;
    tempBigInt = bigInt % (-84);
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, -84);

    // ZERO
    bigInt = 0;
    tempBigInt = bigInt % 3840;
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 0);

    bigInt = 0;
    tempBigInt = bigInt % (-3840);
    refBigInt = 0;
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(bigInt, 0);

    bigInt = 3840;
    EXPECT_THROW(bigInt % 0, std::invalid_argument);

    bigInt = -3840;
    EXPECT_THROW(bigInt % 0, std::invalid_argument);

    bigInt = 0;
    EXPECT_THROW(bigInt % 0, std::invalid_argument);

    // BIG NUMBER
    bigInt = std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                         "9999999999999937");
    tempBigInt = bigInt % std::string("10");
    refBigInt = std::string("7");
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(
        bigInt,
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "9999999999999937"));

    tempBigInt =
        bigInt %
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "99999999999999377");
    refBigInt =
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "9999999999999937");
    EXPECT_EQ(tempBigInt, refBigInt);
    EXPECT_EQ(
        bigInt,
        std::string("99999999999999999999999999999999999999999999999999999999999999999999"
                    "9999999999999937"));
}