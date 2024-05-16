from bisect import bisect_left


def count_triangles(a, n):
    cnt = 0
    for i in range(n-2):
        for j in range(i + 1, n-1):
            mins = a[j] - a[i]
            maxs = a[i] + a[j]
            l = bisect_left(a, mins, lo=j+1)
            r = bisect_left(a, maxs, lo=j+1)
            cnt += r - l
    return cnt


n = int(input())
a = sorted([int(input()) for _ in range(n)])
print(count_triangles(a, n))
