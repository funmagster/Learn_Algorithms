def find_nearest(n, mas, x):
    elem = 0
    dif = abs(mas[0] - x)
    for ind in range(1, n):
        dif_curr = abs(mas[ind] - x)
        if dif_curr < dif:
            elem = ind
            dif = dif_curr
    return mas[elem]


n = int(input())
mas = list(map(int, input().split()))
x = int(input())
print(find_nearest(n, mas, x))
