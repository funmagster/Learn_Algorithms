def count_seq(n, k):
    dp = [[1, k - 1]]
    for i in range(1, n):
        dp.append([dp[i - 1][1], (k - 1)*(dp[i - 1][0] + dp[i - 1][1])])
    return sum(dp[-1])


n, k = map(int, input().split())
print(count_seq(n, k))
