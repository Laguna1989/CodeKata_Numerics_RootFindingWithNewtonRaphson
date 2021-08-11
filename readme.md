# Overview

This is a Code Kata about numerical rootfinding with the Newton-Raphson method. Please check out the
other [Code Nummies](https://github.com/Laguna1989/CodeNummies_Overview).

# Theory

## Rootfinding

Rootfinding is a central problem in maths. If there is no analytic solution for an equation, e.g. `x = cos(x)`, numeric
rootfinding yields an approximated solution for the equation, by solving `0 = cos(x) - x`.

## The Newton-Raphson Method

![ani](https://user-images.githubusercontent.com/2394228/128812604-0d70c463-d239-45ea-93f3-7363b4e28fe1.gif)

We know that a function `f(x)` has a zero at `x'` close to a starting value of `x0`. The idea of the Newton-Raphson
methods is to make use of the first derivative `f'(x)` to calculate an approximation of `x'` iteratively.

The tangent at position `x0` is given via `T(x) = f(x0) + (x-x0) * f'(x0)`. The Newton-Raphson method uses the zero of
the tangent as the next iteration value. This is achieved by setting `T(x1) = 0` and solving for `x1`, which yields

`x1 = x0 - f(x)/f'(x)`

The iteration ends, when `f(x)` is smaller than the accepted error `delta`.

### Benefits

* Fast convergence (e.g. when compared to bisection)
* Constantly increases precision with each iteration
* Works for functions of multiple variables

### Limitations

* Needs a good starting point
* Knowledge needed about `f(x)` **and** `f'(x)`
* Does not work in some edge cases, e.g. `f'(x)` very close to zero

# Exercise

## 1. Newton-Raphson implementation

Replace the fake implementation
function `newton_raphson(std::function<double(double)> const& f, std::function<double(double)> const& d, double x0, double delta)`
in `src/newton_raphson.cpp`. The tests in `tests/newton_raphson_tests.cpp` will show you if your implementation is
correct.

Feel free to test the bisection with your own functions.

## 2. Shortcomings of the Newton-Raphson method

Analyze what could happen for the following functions, if you choose a bad starting point.

* `f(x) = x * sin(x) * log(x)`
* `f(x) = x / (1+x*x)`
* `f(x) = x*x*x*x`

Think about ways how to prevent such issues.

### Hint

It might be very helpful to plot the function in your favourite plotting tool (e.g. matplotlib, gnuplot, wolframalpha,
...)

# References

* [Newton's method on Wikipedia](https://en.wikipedia.org/wiki/Newton%27s_method)
* [Newton-Raphson method by MathAndPhysics](https://www.youtube.com/watch?v=qlNqPE_X4ME&ab_channel=MathAndPhysics)
