from bisect import bisect_left

n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
for elem in b:
    ind = bisect_left(a, elem)
    if ind < n and a[ind] == elem:
        print('YES')
    else:
        print('NO')
