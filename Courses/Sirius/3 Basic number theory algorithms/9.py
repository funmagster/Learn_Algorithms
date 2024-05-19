from math import gcd


def phi(n):
    res = n
    p = 2
    while p * p <= n:
        if n % p == 0:
            res -= res // p
        while n % p == 0:
            n //= p
        p += 1
    if n > 1:
        res -= res // n
    return res


def get_reciprocal_number(m, a):
    if gcd(m, a) != 1:
        return -1

    return pow(a, phi(m) - 1, m)


m, a = map(int, input().split())
print(get_reciprocal_number(m, a))
