def get_profit(n, x, a, b):
    i_best = 0
    j_best = 0
    i_min = 0
    max_profit = 0
    for j in range(1, n):
        if a[j] < a[i_min]:
            i_min = j
        current_profit = (x // a[i_min]) * b[j] + (x % a[i_min])
        if current_profit > max_profit:
            j_best, i_best = j, i_min
            max_profit = current_profit
    if max_profit > x:
        return max_profit, (i_best + 1, j_best + 1)
    return x, (-1, -1)


n, x = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
d, days = get_profit(n, x, a, b)
print(d)
print(*days)
    