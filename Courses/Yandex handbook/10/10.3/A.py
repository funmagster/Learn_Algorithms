def dfs(v, graph):
    used = [0] * n
    stack = [v]
    used[v] = 1
    visited = 0
    while stack:
        v = stack.pop()
        for u in graph[v]:
            if used[u] == 0:
                visited += 1
                stack.append(u)
                used[u] = 1
    return visited


def determine_the_level(n, graph):
    winers = [-1]*n
    for i in range(n):
        visited = dfs(i, graph)
        if winers[visited] == -1:
            winers[visited] = 1
        else:
            return 'NO'
    return 'YES'


n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
    u, v, t = map(int, input().split())
    if t == 1:
        graph[u - 1].append(v - 1)
    elif t == 2:
        graph[v - 1].append(u - 1)
print(determine_the_level(n, graph))
