from math import ceil


def factorization(n):
    p = {}
    y = 1
    d = 2
    while d * d <= n:
        cnt = 0
        while n % d == 0:
            n //= d
            cnt += 1
        if cnt > 0:
            p[d] = cnt
            y *= d
        d += 1
    if n > 1:
        p[n] = 1
        y *= n
    return p, y


def find_n(a):
    p, y = factorization(a)
    if y >= 29:
        return y
    for k in range(1, 1_000_000_000):
        n = k * y
        if pow(n, n, a) == 0:
            return n


def find_n_2(a):
    for n in range(1, a + 1):
        if pow(n, n, a) == 0:
            return n
    return -1


a = int(input())
print(find_n(a))
