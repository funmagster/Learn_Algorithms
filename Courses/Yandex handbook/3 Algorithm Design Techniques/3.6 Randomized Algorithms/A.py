def lomuto_partition(mas, n):
    j = 0
    support_elem = mas[0]
    for i in range(1, n):
        if support_elem >= mas[i]:
            j += 1
            mas[i], mas[j] = mas[j], mas[i]
    mas[0], mas[j] = mas[j], mas[0]
    return mas


n = int(input())
mas = list(map(int, input().split()))
print(*lomuto_partition(mas, n))
