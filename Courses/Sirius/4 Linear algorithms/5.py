def answer(n, m, h):
    pr = [0] * (n)
    for i in range(1, n):
        pr[i] = pr[i - 1] + int(h[i] > h[i - 1])
    for _ in range(m):
        l, r = map(int, input().split())
        print(pr[r - 1] - pr[l - 1])


n, m = map(int, input().split())
h = list(map(int, input().split()))
answer(n, m, h)
