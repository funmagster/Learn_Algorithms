n, m = map(int, input().split())
graph_1 = [['0'] * n for _ in range(n)]
graph_2 = [['0'] * n for _ in range(n)]
for _ in range(m):
    k, *road = map(int, input().split())
    for i in range(1, k):
        # ---------------------------------------
        graph_1[road[i] - 1][road[i - 1] - 1] = '1'
        graph_1[road[i - 1] - 1][road[i] - 1] = '1'
        # ---------------------------------------
    for j in range(k):
        for l in range(j + 1, k):
            graph_2[road[j] - 1][road[l] - 1] = '1'
            graph_2[road[l] - 1][road[j] - 1] = '1'
for i1 in graph_1:
    print(*i1, sep=' ')
for i2 in graph_2:
    print(*i2, sep=' ')
