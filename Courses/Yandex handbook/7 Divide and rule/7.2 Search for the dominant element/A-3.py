def find_dominant_On(mas, n):
    if n == 1:
        return 1
    if n % 2:
        mas.append(mas[-2])

    new_mas_1 = []
    i = 0
    while i < n:
        if mas[i] == mas[i+1]:
            new_mas_1.append(mas[i])
        i += 2
    LEN_MAS = len(new_mas_1)
    while LEN_MAS > 1:

        if LEN_MAS % 2:
            new_mas_1.append(new_mas_1[-2])

        new_mas_2 = []
        i = 0
        while i < LEN_MAS:
            if new_mas_1[i] == new_mas_1[i + 1]:
                new_mas_2.append(new_mas_1[i])
            i += 2
        LEN_MAS = len(new_mas_2)
        new_mas_1 = new_mas_2
    return LEN_MAS


n = int(input())
mas = list(map(int, input().split()))
print(find_dominant_On(mas, n))
