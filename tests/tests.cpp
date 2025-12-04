#include <catch2/catch_test_macros.hpp>

uint32_t Factorial(uint32_t number)
{
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[factorial]")
{
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
}

TEST_CASE("Factorials are computed wrong", "[factorial]")
{
    REQUIRE(Factorial(1) != 2);
    REQUIRE(Factorial(2) != 3);
    REQUIRE(Factorial(3) != 7);
    REQUIRE(Factorial(5) != 21);
}
