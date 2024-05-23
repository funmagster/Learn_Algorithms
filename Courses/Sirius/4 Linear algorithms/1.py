def find_ij(n, a):
    i_best = 0
    j_best = 1
    i_min = 0
    for j in range(2, n):
        if a[j - 1] < a[i_min]:
            i_min = j - 1
        if a[j] / a[i_min] > a[j_best] / a[i_best]:
            i_best = i_min
            j_best = j
    if a[j_best] / a[i_min] <= 1:
        return 0, 0
    return i_best + 1, j_best + 1


n = int(input())
a = list(map(int, input().split()))
print(*find_ij(n, a))
