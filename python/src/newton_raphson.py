def newton_raphon(f, d, x0, delta):
    x = x0
    v = f(x)
    while delta < abs(v):
        x = x - v / d(x)
        v = f(x)
    return x