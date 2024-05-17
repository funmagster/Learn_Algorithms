from math import gcd


def cut_fraction(a, b):
    GCD = gcd(a, b)
    return a // GCD, b // GCD


a, b = map(int, input().split())
print(*cut_fraction(a, b))