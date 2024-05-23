def calk_min_time(n, times):
    if n == 1:
        return times[0][0]
    dp = [
        0, times[0][0],
        min(times[0][1], times[0][0] + times[1][0])
    ]
    for i in range(3, n + 1):
        add = min(
            dp[i - 1] + times[i - 1][0],
            dp[i - 2] + times[i - 2][1],
            dp[i - 3] + times[i - 3][2]
        )
        dp.append(add)
    return dp[n]


n = int(input())
times = [tuple(map(int, input().split())) for _ in range(n)]
print(calk_min_time(n, times))
