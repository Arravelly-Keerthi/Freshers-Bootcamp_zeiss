#include <gtest/gtest.h>
#include "Header1.h"

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    std::string input = "";
    int result = StringCalculator::add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedresult = 0;
    std::string input = "0";
    int result = StringCalculator::add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
    int expectedresult = 3;
    std::string input = "1,2";
    int result = StringCalculator::add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectExceptionForNegativeNumbers) {
    ASSERT_THROW({
        std::string input = "-1,2";
        StringCalculator::add(input);
        }, std::runtime_error);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    std::string input = "1\n2,3";
    int result = StringCalculator::add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 1;
    std::string input = "1,1001";
    int result = StringCalculator::add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
    int expectedresult = 3;
    std::string input = "//;\n1;2";
    int result = StringCalculator::add(input);

    ASSERT_EQ(result, expectedresult);
}
