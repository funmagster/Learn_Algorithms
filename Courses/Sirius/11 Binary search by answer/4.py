def ok(mid, n, k, coords):
    k -= 1
    last = coords[0]
    for i in range(1, n):
        if coords[i] - last >= mid:
            k -=1
            last = coords[i]
    return k <= 0


def calk_min_dist(n, k, coords):
    l = 0
    r = coords[-1] - coords[0] + 1
    while r - l > 1:
        mid = (l + r) // 2
        if ok(mid, n, k, coords):
            l = mid
        else:
            r = mid
    return l


n, k = map(int, input().split())
coords = list(map(int, input().split()))
print(calk_min_dist(n, k, coords))
