#include "newton_raphson.hpp"

double newton_raphson(std::function<double(double)> const& f,
    std::function<double(double)> const& d, double x0, double delta)
{
    double x = x0;
    double v = f(x);

    while (delta < abs(v)) {
        x = x - f(x) / d(x);
        v = f(x);
    }
    return x;
}
