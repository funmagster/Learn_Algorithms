def f(x, c):
    return x*x + x**0.5 - c


def fins_root(c):
    l = 0
    r = c
    for _ in range(200):
        mid = (l + r) / 2
        if f(mid, c) >= 0:
            r = mid
        else:
            l = mid
    return r


c = float(input())
print(fins_root(c))