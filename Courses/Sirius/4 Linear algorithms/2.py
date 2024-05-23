def max_cells(n, k, cells):
    i_best = 0
    j_best = k + 1
    i_max = 0
    for j in range(k + 2, n):
        if cells[j - k - 1] > cells[i_max]:
            i_max = j - k - 1
        if cells[j] + cells[i_max] > cells[j_best] + cells[i_best]:
            j_best, i_best = j, i_max
    return i_best + 1, j_best + 1


n, k = map(int, input().split())
cells = list(map(int, input().split()))
print(*max_cells(n, k, cells))
