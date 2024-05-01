def R(n, m):
    n += 1
    m += 1
    dp = [[0]*m for _ in range(n)]
    dp[0][0] = 'L'
    for i in range(1, n):
        if dp[i-1][0] == 'W':
            dp[i][0] = 'L'
        else:
            dp[i][0] = 'W'
    for j in range(1, m):
        if dp[0][j-1] == 'W':
            dp[0][j] = 'L'
        else:
            dp[0][j] = 'W'
    for i in range(1, n):
        for j in range(1, m):
            if dp[i-1][j-1] == 'W' and dp[i][j-1] == 'W' and dp[i-1][j] == 'W':
                dp[i][j] = 'L'
            else:
                dp[i][j] = 'W'
    if dp[-1][-1] == 'L':
        return 'Loose'
    return 'Win'


n, m = map(int, input().split())
print(R(n, m))