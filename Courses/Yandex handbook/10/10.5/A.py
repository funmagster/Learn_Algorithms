import heapq
from collections import deque


def get_path(start, end, graph, n):
    distances = [float('inf')] * n
    distances[start] = 0
    parents = [None] * n
    priority_queue = [(0, start)]

    while priority_queue:
        dist, v = heapq.heappop(priority_queue)
        if dist > distances[v]:
            continue
        if v == end:
            break
        for u, c in graph[v]:
            distance = dist + c
            if distance < distances[u]:
                distances[u] = distance
                heapq.heappush(priority_queue, (distance, u))
                parents[u] = v

    path = deque([])
    vertex = end
    while vertex is not None:
        path.appendleft(vertex + 1)
        vertex = parents[vertex]
    return list(path)


def get_directions(n, V, o1, o2, o3, graph):
    answer = []
    answer.extend(
        get_path(V - 1, o1 - 1, graph, n)
    )
    answer.extend(
        get_path(o1 - 1, o2 - 1, graph, n)[1:]
    )
    answer.extend(
        get_path(o2 - 1, o3 - 1, graph, n)[1:]
    )
    answer.extend(
        get_path(o3 - 1, V - 1, graph, n)[1:]
    )
    return len(answer), answer


n, m, V, o1, o2, o3 = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
    u, v, c = map(int, input().split())
    graph[u - 1].append((v - 1, c))
    graph[v - 1].append((u - 1, c))

s, directions = get_directions(n, V, o1, o2, o3, graph)
print(s)
print(*directions)
