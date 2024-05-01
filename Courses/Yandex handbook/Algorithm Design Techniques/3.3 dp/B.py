def R(n, m):
    dp = [['L']*(m+2) for _ in range(n + 2)]
    for i in range(2, n+2):
        for j in range(2, m+2):
            if dp[i-2][j] == 'W' and dp[i][j-1] == 'W' and dp[i-1][j] == 'W'\
                    and dp[i][j-2] == 'W' and dp[i-1][j-2] == 'W'\
                    and dp[i-2][j-1] == 'W':
                dp[i][j] = 'L'
            else:
                dp[i][j] = 'W'
    if dp[-1][-1] == 'L':
        return 'Loose'
    return 'Win'


n, m = map(int, input().split())
print(R(n, m))