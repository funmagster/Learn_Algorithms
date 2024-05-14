answer_a_1 = '''0 1 1 0 0
1 0 1 1 1
1 1 0 1 0
0 1 1 0 0
0 1 0 0 0
0 1 1 1 1
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
1 1 1 1 0'''

answer_a_2 = '''0 1 1 0 0
1 0 1 1 0
1 1 0 1 1
0 1 1 0 1
0 0 1 1 0
0 1 1 1 1
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
1 1 1 1 0'''


def test_A(answer_a):
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
    s = ''
    for i1 in graph_1:
        s += " ".join(i1)
        s += '\n'
    for i2 in graph_2:
        s += ' '.join(i2)
        s += '\n'
    assert s.rstrip('\n') == answer_a
    print('Ok')


if __name__ == '__main__':
    test_A(answer_a_1)
    test_A(answer_a_2)
