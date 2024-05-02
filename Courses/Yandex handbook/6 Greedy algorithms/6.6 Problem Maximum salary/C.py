from math import ceil


def king_max(r, c):
    return (r*c) - (ceil(r/3) * ceil(c/3))


r, c = map(int, input().split())
print(king_max(r, c))
