def worst_entrance(n):
    mas = [[1]]
    for i in range(1, n):
        new_mas = mas[i - 1][:i//2] + [i + 1] + mas[i - 1][i//2:]
        mas.append(new_mas)
    return mas[n - 1]


n = int(input())
print(*worst_entrance(n))
