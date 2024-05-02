def maximum_loot(w, spices, n):
    value = 0
    i = 0
    while w != 0 and i < n:
        amount = min(w, spices[i][1])
        value += spices[i][0] * amount / spices[i][1]
        w -= amount
        i += 1
    return value


n, w = map(int, input().split())
spices = sorted(
    [tuple(map(int, input().split())) for _ in range(n)],
    key=lambda x: x[0] / x[1],
    reverse=True
)
print(maximum_loot(w, spices, n))
