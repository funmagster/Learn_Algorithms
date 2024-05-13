def find_max_diff(n, mas):
    j_min = n - 1
    i_best = n - 2
    j_best = n - 1
    for i in range(n - 3, -1, -1):
        if mas[i + 1] < mas[j_min]:
            j_min = i + 1
        if mas[i] - mas[j_min] > mas[i_best] - mas[j_best]:
            i_best = i
            j_best = j_min
    return i_best + 1, j_best + 1


def find_min_diff(n, mas):
    i_best = 0
    j_best = 1
    i_min = 0
    for j in range(2, n):
        if mas[j - 1] < mas[i_min]:
            i_min = j - 1
        if mas[i_min] - mas[j] < mas[i_best] - mas[j_best]:
            j_best = j
            i_best = i_min
    return i_best + 1, j_best + 1


n = int(input())
mas = list(map(int, input().split()))
print(*find_min_diff(n, mas))
print(*find_max_diff(n, mas))
