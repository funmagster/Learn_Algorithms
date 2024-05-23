def count_routes(n):
    dp = [0, 0, 1]
    for i in range(3, n + 3):
        dp.append(dp[i - 1] + dp[i - 2] + dp[i - 3])
    return dp[-1]


n = int(input())
print(count_routes(n))
