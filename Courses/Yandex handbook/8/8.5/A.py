def lcs(n, mas_1, m, mas_2):
    dp = [[0]*(m + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            if mas_1[i - 1] == mas_2[j - 1]:
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1)
    return dp[-1][-1]


n = int(input())
mas_1 = list(map(int, input().split()))
m = int(input())
mas_2 = list(map(int, input().split()))
print(lcs(n, mas_1, m, mas_2))
