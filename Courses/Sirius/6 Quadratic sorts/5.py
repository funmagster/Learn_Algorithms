def count_swap(n, mas):
    unordered = True
    cnt = 0
    while unordered:
        unordered = False
        for j in range(n - 1):
            if mas[j] > mas[j + 1]:
                mas[j], mas[j + 1] = mas[j + 1], mas[j]
                cnt += 1
                unordered = True
        n -= 1
    return cnt


n = int(input())
mas = list(map(int, input().split()))
print(count_swap(n, mas))