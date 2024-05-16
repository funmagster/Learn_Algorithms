def knapsack(w, n, weight, pack):
    if (w, n) not in pack:
        if n == 0 or w == 0:
            pack[(w, n)] = 0
        elif weight[n - 1] > w:
            pack[(w, n)] = knapsack(w, n-1, weight, pack)
        else:
            pack[(w, n)] = max(
                weight[n - 1] + knapsack(w - weight[n - 1], n-1, weight, pack),
                knapsack(w, n-1, weight, pack)
            )
    return pack[(w, n)]


w, n = map(int, input().split())
weight = list(map(int, input().split()))
pack = {}
print(knapsack(w, n, weight, pack))
