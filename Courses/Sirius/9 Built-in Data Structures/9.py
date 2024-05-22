from collections import deque


n = int(input())
tree = [[] for _ in range(n)]
used = {}
name = {}
cnt = 0
for _ in range(n - 1):
    a, b = input().split()
    if a not in used:
        used[a] = cnt
        name[cnt] = a
        cnt += 1
    if b not in used:
        used[b] = cnt
        name[cnt] = b
        cnt += 1
    tree[used[b]].append(used[a])

dist = [0]*n
for v in range(n):
    if dist[v] == 0:
        q = deque([v])
        while q:
            v = q.popleft()
            for u in tree[v]:
                q.append(u)
                dist[u] = max(dist[u], dist[v] + 1)
answer = dict(sorted({name[i]: dist[i] for i in range(n)}.items()))
for name, deep in answer.items():
    print(name, deep)
