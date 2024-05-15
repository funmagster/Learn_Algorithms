def dfs(start, graph, used):
    used[start] = 1
    stack = [start]
    while stack:
        v = stack.pop()
        for u in graph[v]:
            if not used[u]:
                stack.append(u)
                used[u] = 1
    return used


n, m = map(int, input().split())
graph = [[] for _ in range(n)]
used = [0]*n
for _ in range(m):
    u, v = map(int, input().split())
    graph[u - 1].append(v - 1)
    graph[v - 1].append(u - 1)


used = dfs(0, graph, used)
c = 0
answer = []
for v in range(1, n):
    if not used[v]:
        c += 1
        answer.append((v + 1, v))
        used = dfs(v, graph, used)

print(c)
for i in range(c):
    print(*answer[i])
