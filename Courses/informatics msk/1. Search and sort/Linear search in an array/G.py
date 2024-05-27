def min_two_elem(n, mas):
    elem_1 = 0
    elem_2 = 1
    if mas[elem_2] < mas[elem_1]:
        elem_1, elem_2 = elem_2, elem_1
    for ind in range(2, n):
        if mas[ind] < mas[elem_1]:
            elem_1, elem_2 = ind, elem_1
        elif mas[ind] < mas[elem_2]:
            elem_2 = ind
    return mas[elem_1], mas[elem_2]


n = int(input())
mas = list(map(int, input().split()))
print(*min_two_elem(n, mas))
