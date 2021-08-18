#include "newton_raphson.hpp"
#include <gtest/gtest.h>

TEST(Newton, LinearFunction)
{
    double const x_zero = 0;

    auto f = [](double x) { return x; };
    auto d = [](double /*x*/) { return 1; };

    auto const x = newton_raphson(f, d, 3.0, 0.001);
    ASSERT_LT(abs(x - x_zero), 0.0001);
}

TEST(Newton, sine)
{
    double const delta = 0.00001;
    double const x_zero = 0;
    auto f = [](double x) { return sin(x); };
    auto d = [](double x) { return cos(x); };

    auto const x = newton_raphson(f, d, 0.2, delta);
    ASSERT_LT(abs(x - x_zero), 0.0001);
}

class NewtonWithStartParamTestFixture : public ::testing::TestWithParam<double> {
};

TEST_P(NewtonWithStartParamTestFixture, transcendentFunction)
{
    double const x0 = GetParam();
    double const delta = 0.0001;
    double const x_root = 0.739085;
    auto const f = [](double x) { return cos(x) - x; };
    auto const d = [](double x) { return -sin(x) - 1; };

    auto const x = newton_raphson(f, d, x0, delta);
    ASSERT_LT(abs(x - x_root), 0.0001);
}

INSTANTIATE_TEST_SUITE_P(NewtonWithStartParamTestNewtonWithStartParamTestFixture,
    NewtonWithStartParamTestFixture, ::testing::Values(3, 2, 1, 0.5, 0.25, 0.1));
