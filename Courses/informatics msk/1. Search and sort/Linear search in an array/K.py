def counter_operation(mas):
    min_i = 0
    max_i = 0
    for i in range(1, len(mas)):
        if mas[i] < mas[min_i]:
            min_i = i
        if mas[i] > mas[max_i]:
            max_i = i
    elem_max = mas[max_i]
    elem_min = mas[min_i]
    for i in range(len(mas)):
        if mas[i] == elem_max:
            mas[i] = elem_min
    return mas


mas = [int(i) for ind, i in enumerate(input().split()) if ind != 0]
print(*counter_operation(mas))
