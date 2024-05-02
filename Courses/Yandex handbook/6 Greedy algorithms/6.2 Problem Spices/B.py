def maximum_count(n, s, cost):
    i = 0
    while s != 0 and i < n:
        if cost[i] <= s:
            s -= cost[i]
            i += 1
        else:
            return i
    return i


n, s = map(int, input().split())
cost = sorted([int(input()) for _ in range(n)])
print(maximum_count(n, s, cost))
