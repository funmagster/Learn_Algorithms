from random import randint


def partition(mas, n, target, start):
    j = target

    for elem in range(target - 1, start - 1, -1):
        if mas[elem] == mas[target]:
            j -= 1
            mas[elem], mas[j] = mas[j], mas[elem]
        elif mas[elem] > mas[target]:
            j -= 1
            mas[target], mas[elem], mas[j] = mas[elem], mas[j], mas[target]
            target -= 1

    for elem in range(target + 1, start + n):
        if mas[elem] == mas[target]:
            target += 1
            mas[elem], mas[target] = mas[target], mas[elem]

        elif mas[elem] < mas[target]:
            mas[j], mas[elem] = mas[elem], mas[j]
            j += 1
            target += 1
            mas[elem], mas[target] = mas[target], mas[elem]
    return j, target


def randomized_quick_sort(n, mas, start):
    if n < 1:
        return []
    elif n == 1:
        return [mas[start]]

    end = start + n
    ind_m = randint(start, end - 1)
    l, r = partition(mas, n, ind_m, start)
    c_small = randomized_quick_sort(l - start, mas, start)
    c_large = randomized_quick_sort(end - r - 1, mas, r + 1)
    c_sorted = c_small + [mas[l]]*(r - l + 1) + c_large
    return c_sorted


n = int(input())
mas = list(map(int, input().split()))
print(*randomized_quick_sort(n, mas, start=0))
