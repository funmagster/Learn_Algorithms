n = int(input())
mas = list(map(int, input().split()))
maxs_1, maxs_2 = 0, 1
if mas[maxs_1] < mas[maxs_2]:
    maxs_1, maxs_2 = maxs_2, maxs_1
for i in range(2, n):
    if mas[i] > mas[maxs_1]:
        maxs_1, maxs_2 = i, maxs_1
    elif mas[i] > mas[maxs_2]:
        maxs_2 = i
print(mas[maxs_1]*mas[maxs_2])
