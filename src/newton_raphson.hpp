#ifndef CODE_KATA_NEWTON_RAPHSON_HPP
#define CODE_KATA_NEWTON_RAPHSON_HPP

#include <functional>

double newton_raphson(std::function<double(double)> const& f,
    std::function<double(double)> const& d, double x0, double delta);

#endif // CODE_KATA_NEWTON_RAPHSON_HPP
