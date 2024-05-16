from bisect import bisect_left, bisect_right


n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
for elem in b:
    ind_l = bisect_left(a, elem)
    if ind_l < n and a[ind_l] == elem:
        ind_r = bisect_right(a, elem)
        print(ind_l + 1, ind_r)
    else:
        print(0)
