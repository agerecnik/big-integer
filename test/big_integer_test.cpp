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

    EXPECT_THROW(BigIntNS::BigInt bigInt16("");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt bigInt16("-");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt bigInt16("--");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt bigInt16("-a");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt bigInt16("-3342a");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt bigInt16("-334c2");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt bigInt16("33-42");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt bigInt16("3342-");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt bigInt16("334c2");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt bigInt16("c3342");, std::invalid_argument);
    EXPECT_THROW(BigIntNS::BigInt bigInt16("3342c");, std::invalid_argument);
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

    bigInt1 = -50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_FALSE(bigInt1 == bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = -50000000000000000;
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

    bigInt1 = -50000000000000000;
    bigInt2 = 50000000000000000;
    EXPECT_TRUE(bigInt1 != bigInt2);

    bigInt1 = 50000000000000000;
    bigInt2 = -50000000000000000;
    EXPECT_TRUE(bigInt1 != bigInt2);
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