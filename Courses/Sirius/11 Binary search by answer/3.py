def ok(mid, x, y, n):
    # first
    mid -= min(x, y)
    if mid <= 0:
        return n == 1 and mid == 0
    return 1 + mid // x + mid // y >= n


def calk_min_time(n, x, y):
    l = 0
    r = n * max(x, y)
    while r - l > 1:
        mid = (r + l) // 2
        if ok(mid, x, y, n):
            r = mid
        else:
            l = mid
    return r


n, x, y = map(int, input().split())
print(calk_min_time(n, x, y))
