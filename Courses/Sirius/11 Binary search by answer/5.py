from math import ceil


def ok(mid, h, m):
    for moster in h:
        m -= ceil(moster / mid)
    return m >= 0


def find_min_x(n, h, m):
    if m < n:
        return -1
    l = 0
    r = 10e9
    while r - l > 1:
        mid = (l + r) // 2
        if ok(mid, h, m):
            r = mid
        else:
            l = mid
    return int(r)


n = int(input())
h = list(map(int, input().split()))
m = int(input())
print(find_min_x(n, h, m))
