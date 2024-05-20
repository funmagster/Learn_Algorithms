def extend_gcd(a, b):
    if b == 0:
        return a, 1, 0
    d, x0, y0 = extend_gcd(b, a % b)
    x = y0
    y = x0 - (a // b) * y0
    return d, x, y


def find_root(a, b, c):
    d, x0, y0 = extend_gcd(a, b)
    if d == 0 or c % d != 0:
        return -1
    x, y = (c // d) * x0, (c // d) * y0
    while x > 0:
        x, y = x - (b // d),  y + (a // d)
        if x < 0:
            x, y = x + (b // d),  y - (a // d)
            break
    while x < 0:
        x, y = x + (b // d),  y - (a // d)
    return x, y


a, b, c = map(int, input().split())
ans = find_root(a, b, c)
if ans == -1:
    print(-1)
else:
    print(*ans)
