def phi(n):
    res = n
    p = 2
    while p*p <= n:
        if n % p == 0:
            res -= res // p
        while n % p == 0:
            n //= p
        p += 1
    if n > 1:
        res -= res // n
    return res


n = int(input())
print(phi(n))
