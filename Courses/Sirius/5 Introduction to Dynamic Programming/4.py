def calk_min_op(n):
    dp = [0, 0]
    for i in range(2, n + 1):
        add = dp[i - 1]
        if i % 2 == 0:
            add = min(add, dp[i // 2])
        if i % 3 == 0:
            add = min(add, dp[i // 3])
        dp.append(add + 1)
    return dp[-1]


n = int(input())
print(calk_min_op(n))
