from math import cos
from math import sin
import pytest
from newton_raphson import newton_raphon

def test_newton_linear_function():
    x_zero = 0.0

    def f(x):
        return x

    def d(x):
        return 1

    x = newton_raphon(f, d, 3.0, 0.001)

    assert abs(x - x_zero) < 0.0001


def test_newton_sine():
    delta = 0.00001
    x_zero = 0.0

    def f(x):
        return sin(x)

    def d(x):
        return cos(x)

    x = newton_raphon(f, d, 0.2, delta)
    assert abs(x - x_zero) < 0.0001


@pytest.mark.parametrize("x0", [3.0, 2.0, 1.0, 0.5, 0.25, 0.1])
def test_newton_transcendent_function(x0):
    delta = 0.0001
    x_root = 0.739085

    def f(x):
        return cos(x) - x

    def d(x):
        return -sin(x) - 1.0

    x = newton_raphon(f, d, x0, delta)
    assert abs(x - x_root) < 0.0001

