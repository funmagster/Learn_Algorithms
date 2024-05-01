n = int(input())
dp = [0, 1, 3, 5]
for n_i in range(4, n + 1):
    if (n_i - 1) % 2 == 0:
        # ac = dp[(n_i - 1) // 2]
        dp.append(4*dp[(n_i - 1) // 2] + 1)
    else:
        # ac = dp[(n_i - 1) // 2]
        # cac = dp[(n_i - 1) // 2 - 1]
        dp.append(2 * (dp[(n_i - 1) // 2] + dp[(n_i - 1) // 2 + 1]) + 1)
print(dp[-1])
