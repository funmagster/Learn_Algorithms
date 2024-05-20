def sorted_list(n, mas):
    for i in range(n - 1):
        i_max = i
        for j in range(i + 1, n):
            if mas[j][1] > mas[i_max][1]:
                i_max = j
            elif mas[j][1] == mas[i_max][1] and mas[j][0] < mas[i_max][0]:
                i_max = j
        mas[i], mas[i_max] = mas[i_max], mas[i]
    return mas


n = int(input())
mas = [tuple(map(int, input().split())) for _ in range(n)]
for ans in sorted_list(n, mas):
    print(*ans)
