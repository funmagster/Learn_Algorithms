def lcs_2(n, mas_1, m, mas_2, k, mas_3):
    dp = [[[0]*(k + 1) for _ in range(m + 1)] for __ in range(n + 1)]
    # print(dp)
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            for c in range(1, k + 1):
                dp[i][j][c] = max(dp[i-1][j][c], dp[i][j-1][c], dp[i][j][c-1])
                if mas_1[i - 1] == mas_2[j - 1] == mas_3[c - 1]:
                    dp[i][j][c] = max(dp[i][j][c], dp[i-1][j-1][c-1] + 1)
    return dp[-1][-1][-1]


n = int(input())
mas_1 = list(map(int, input().split()))
m = int(input())
mas_2 = list(map(int, input().split()))
k = int(input())
mas_3 = list(map(int, input().split()))
print(lcs_2(n, mas_1, m, mas_2, k, mas_3))
