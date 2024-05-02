def is_dominant_element(dominant, mas, n, start, end):
    count = 0
    for elem_ind in range(start, end):
        if mas[elem_ind] == dominant:
            count += 1
    if count > n // 2:
        return dominant
    return -1


def is_dominant_two_element(first, second, mas, n, start, end):
    count_first = 0
    count_second = 0
    for elem_ind in range(start, end):
        if mas[elem_ind] == first:
            count_first += 1
        elif mas[elem_ind] == second:
            count_second += 1
    if count_first > n // 2:
        return first
    elif count_second > n // 2:
        return second
    return -1


def find_dominant_element(mas, n, start, end):
    if n == 1:
        return mas[start]
    first = find_dominant_element(mas, n // 2, start, start + n // 2)
    second = find_dominant_element(mas, n - n // 2, start + n // 2, start + n)
    if first != -1:
        if second != -1:
            return is_dominant_two_element(first, second, mas, n, start, end)
        else:
            return is_dominant_element(first, mas, n, start, end)
    else:
        return is_dominant_element(second, mas, n, start, end)


def chech_dominant(mas, n):
    if find_dominant_element(mas, n, 0, n) != -1:
        return 1
    return 0


n = int(input())
mas = list(map(int, input().split()))
print(chech_dominant(mas, n))