def get_next_vertex(v):
    for ind, u in enumerate(graph[v]):
        if u == 1:
            yield ind


def dfs_for_adjacency_list(v):
    if not visited[v]:
        answer.append(v)
    visited[v] = 1

    for u in graph[v]:
        if not visited[u]:
            dfs_for_adjacency_list(u)


def dfs_for_adjacency_matrix(v):
    if not visited[v]:
        answer.append(v)
    visited[v] = 1

    for u in get_next_vertex(v):
        if not visited[u]:
            dfs_for_adjacency_list(u)


def main_dfs(graph_in, way_in, n=0):
    global graph, visited, way

    graph = graph_in
    visited = [0 for _ in range(n)]
    way = way_in

    if way == 1:
        for start in range(n):
            if not visited[start]:
                dfs_for_adjacency_list(start)
    elif way == 2:
        for start in range(n):
            if not visited[start]:
                dfs_for_adjacency_matrix(start)

    return answer


answer, graph, visited, way = [], None, None, None
