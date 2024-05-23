def find_k_elem(n, k, m, a):
    pr = [0] * (n + 1)
    for i in range(1, n + 1):
        pr[i] = pr[i - 1] + a[i - 1]
    for i in range(n - k):
        if pr[k + i + 1] - pr[i] == m:
            return i + 1
    return 0


n, k, m = map(int, input().split())
a = list(map(int, input().split()))
print(find_k_elem(n, k, m, a))
