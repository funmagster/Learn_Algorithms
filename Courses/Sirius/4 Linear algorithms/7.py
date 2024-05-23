def max_sum(n, a):
    pr = [0] * (n + 1)
    for i in range(n + 1):
        pr[i] = pr[i - 1] + a[i - 1]
    i_best, j_best, i_min = 0, 0, 0
    for j in range(1, n):
        if pr[j] <= pr[i_min]:
            i_min = j
        if pr[j + 1] - pr[i_min] > pr[j_best + 1] - pr[i_best]:
            j_best, i_best = j, i_min
    return i_best + 1, j_best + 1


n = int(input())
a = [int(input()) for _ in range(n)]
print(*max_sum(n, a), sep='\n')
