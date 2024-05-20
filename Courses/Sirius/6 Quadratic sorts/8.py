def insertion_sort(n, mas):
    for i in range(1, n):
        flag = False
        a_i = mas[i]
        j = i - 1
        while j >= 0 and a_i < mas[j]:
            mas[j + 1] = mas[j]
            j -= 1
            flag = True
        mas[j + 1] = a_i
        if flag:
            print(*mas)


n = int(input())
mas = list(map(int, input().split()))
insertion_sort(n, mas)
