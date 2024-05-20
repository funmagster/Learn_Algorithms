def find_k_jar(n, a, k):
    for i in range(0, k):
        imax = i
        for j in range(i + 1, n):
            if a[j] > a[imax]:
                imax = j
        a[i], a[imax] = a[imax], a[i]
    return a[k - 1]


n, k = map(int, input().split())
a = list(map(int, input().split()))
print(find_k_jar(n, a, k))