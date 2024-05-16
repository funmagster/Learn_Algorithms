def ok(a, w, h, n):
    return (a // w) * (a // h) >= n


def min_size(w, h, n):
    l = 0
    r = n * max(w, h)
    while r - l > 1:
        mid = (r + l) // 2
        if ok(mid, w, h, n):
            r = mid
        else:
            l = mid
    return r


w, h, n = map(int, input().split())
print(min_size(w, h, n))
