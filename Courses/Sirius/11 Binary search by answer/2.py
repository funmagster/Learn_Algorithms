from bisect import bisect_right


def ok(mid, pr, k):
    start = 0
    elem = mid
    for _ in range(k):
        start = bisect_right(a=pr, x=elem, lo=start)
        elem = pr[start-1] + mid
    if elem - mid >= pr[-1]:
        return True
    return False


def get_min_str(n, a, k):
    pr = [a[0]]
    for i in range(1, n):
        pr.append(a[i] + pr[i - 1])
    l = 0
    r = pr[-1]
    while r - l > 1:
        mid = (r + l) // 2
        if ok(mid, pr, k):
            r = mid
        else:
            l = mid
    return r


n = int(input())
a = list(map(int, input().split()))
k = int(input())
print(get_min_str(n, a, k))
