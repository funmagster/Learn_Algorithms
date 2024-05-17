from math import gcd


def count_cells(a, b, c, d):
    delta_x, delta_dy = abs(a - c), abs(b - d)
    return delta_x + delta_dy - gcd(delta_x, delta_dy)


a, b, c, d = map(int, input().split())
print(count_cells(a, b, c, d))
