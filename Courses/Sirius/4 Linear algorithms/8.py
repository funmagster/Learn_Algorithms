def count_ways(n, r, d):
    i = 0
    j = 0
    cnt = 0
    while j < n and i < n - 1:
        if d[j] - d[i] <= r:
            j += 1
        else:
            cnt += n - j
            i += 1
    return cnt


n, r = map(int, input().split())
d = list(map(int, input().split()))
print(count_ways(n, r, d))
