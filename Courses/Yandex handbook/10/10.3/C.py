from collections import deque


def find_shortcut(graph, start, finish):
    q = deque([(start, '')])
    used = set()
    used.add(start)
    while q:
        v, path = q.popleft()
        if v == finish:
            return len(path), path
        for u in graph[v]:
            if u not in used:
                q.append((u, path + get_direction(v, u)))
                used.add(u)
    return -1, -1


def print_graph(graph):
    '''
    Function to check input record
    '''
    for i in graph:
        print(*i)


def get_direction(prev, cur):
    if prev - cur == 1:
        return 'L'
    elif prev - cur == -1:
        return 'R'
    elif prev - cur > 1:
        return 'U'
    elif prev - cur < -1:
        return 'D'


n, m = map(int, input().split())
n_m = (n - 2) * (m - 2)
graph = [[] for _ in range(n_m)]
if n < 3 or m < 3:
    print(-1)
else:
    lab = [[elem for elem in input()] for _ in range(n)]
    start = -1
    finish = -1
    for i in range(1, n - 1):
        for j in range(1, m - 1):
            i_1 = i - 1
            j_1 = j - 1
            if lab[i][j] != '#':
                if lab[i - 1][j] != '#':
                    graph[i_1 * (m - 2) + j_1].append((i_1 - 1) * (m - 2) + j_1)
                if lab[i][j - 1] != '#':
                    graph[i_1 * (m - 2) + j_1].append(i_1 * (m - 2) + j_1 - 1)
                if lab[i][j + 1] != '#':
                    graph[i_1 * (m - 2) + j_1].append(i_1 * (m - 2) + j_1 + 1)
                if lab[i + 1][j] != '#':
                    graph[i_1 * (m - 2) + j_1].append((i_1 + 1) * (m - 2) + j_1)
            if lab[i][j] == 'S':
                start = i_1 * (m - 2) + j_1
            elif lab[i][j] == 'F':
                finish = i_1 * (m - 2) + j_1
    # print_graph(graph)
    dist, path = find_shortcut(graph, start, finish)
    if dist == -1:
        print(-1)
    else:
        print(dist)
        print(path)
