def split(n, values):
    sums = sum(values)
    if sums % 3 != 0:
        return False
    v = sums // 3
    splits = [[[False]*(v+1) for _ in range(v+1)] for __ in range(n+1)]
    splits[0][0][0] = True
    for i in range(1, n + 1):
        for s1 in range(0, v + 1):
            for s2 in range(0, v + 1):
                splits[i][s1][s2] = splits[i-1][s1][s2]
                if s1 >= values[i-1]:
                    splits[i][s1][s2] = splits[i][s1][s2] or splits[i - 1][s1 - values[i-1]][s2]
                if s2 >= values[i-1]:
                    splits[i][s1][s2] = splits[i][s1][s2] or splits[i - 1][s1][s2 - values[i-1]]
    return splits[n][v][v]


n = int(input())
values = list(map(int, input().split()))
print(int(split(n, values)))
