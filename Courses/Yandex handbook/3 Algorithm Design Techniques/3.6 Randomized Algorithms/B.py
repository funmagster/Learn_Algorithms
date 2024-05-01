def lomuto_partition_first(mas, low, high):
    pivot = mas[low]
    i = low
    for j in range(low + 1, high + 1):
        if mas[j] < pivot:
            i += 1
            mas[i], mas[j] = mas[j], mas[i]
    mas[low], mas[i] = mas[i], mas[low]
    return i


def quick_sort_first(mas, low, high):
    if low < high:
        pivot_index = lomuto_partition_first(mas, low, high)
        quick_sort_first(mas, low, pivot_index - 1)
        quick_sort_first(mas, pivot_index + 1, high)


n = int(input())
mas = list(map(int, input().split()))
quick_sort_first(mas, 0, n-1)
print(*mas)
