n = int(input())
mas = list(map(int, input().split()))
for i in range(n):
    for j in range(i+1, n):
        if mas[i] > mas[j]:
            mas[i], mas[j] = mas[j], mas[i]
print(*mas, sep=' ')