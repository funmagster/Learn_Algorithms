def find_depth(L, socks):
    table = [0] * (L + 2)
    for sock in socks:
        l, r = sock[0], sock[1]
        table[l] += 1
        table[r + 1] -= 1
    c = 0
    res = [0] * (L + 2)
    for i in range(len(res)):
        c += table[i]
        res[i] = c
    return res


def solve(l, socks, q):
    table = find_depth(l, socks)
    answer = [table[i] for i in q]
    return answer


l, n, m = map(int, input().split())
socks = [tuple(map(int, input().split())) for _ in range(n)]
q = [int(input()) for _ in range(m)]
print(*solve(l, socks, q), sep='\n')
