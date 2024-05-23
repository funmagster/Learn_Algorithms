def max_sum(n, ladder):
    dp = [0, ladder[0]]
    for i in range(2, n + 1):
        dp.append(max(dp[i - 1], dp[i - 2]) + ladder[i - 1])
    return dp[n]


n = int(input())
ladder = list(map(int, input().split()))
print(max_sum(n, ladder))
