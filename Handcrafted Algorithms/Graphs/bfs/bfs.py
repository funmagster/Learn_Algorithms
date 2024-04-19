from collections import deque


def bfs(v, visited):
    q = deque()

    visited[v] = True
    q.append(v)
    answer = []
    while q:
        ver = q.popleft()
        answer.append(ver)

        for u in graph[ver]:
            if not visited[u]:
                visited[u] = 1
                q.append(u)
    return answer


def main_dfs(start_in, graph_in, n=0):
    global graph, start

    graph = graph_in

    visited = [0 for _ in range(n)]
    answer = bfs(start_in, visited)
    print(*answer)
    return answer


graph, start, n = [[1, 2],
                [0, 3, 4],
                [2, 4],
                [1],
                [1, 2]], 0, 5
main_dfs(start, graph, 5)