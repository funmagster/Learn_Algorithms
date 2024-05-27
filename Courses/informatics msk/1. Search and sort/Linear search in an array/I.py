def count_saddle_points(n, m, mas):
    min_row = []
    max_row = []
    cnt = 0
    for i in range(n):
        min_row.append(min(mas[i]))
    for j in range(m):
        maxs_elem = mas[0][j]
        for i in range(n):
            if mas[i][j] > maxs_elem:
                maxs_elem = mas[i][j]
        max_row.append(maxs_elem)
    for i in range(n):
        for j in range(m):
            if mas[i][j] == min_row[i] == max_row[j]:
                cnt += 1
    return cnt


n, m = map(int, input().split())
mas = [[int(i) for i in input().split()] for _ in range(n)]
print(count_saddle_points(n, m, mas))
