def min_length(n, nails):
    nails.sort()
    if n == 2:
        return nails[1] - nails[0]
    dp = [0, nails[1] - nails[0], nails[2] - nails[0]]
    for i in range(3, n):
        add = min(dp[i - 1], dp[i - 2]) + (nails[i] - nails[i - 1])
        dp.append(add)
    return dp[n - 1]


n = int(input())
nails = list(map(int, input().split()))
print(min_length(n, nails))
