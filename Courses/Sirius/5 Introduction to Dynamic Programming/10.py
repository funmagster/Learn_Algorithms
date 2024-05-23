def get_ents_num_modulo_p(k, p):
    dp = [0, 0, 1]
    for i in range(3, k + 1):
        add = dp[i - 1] % p
        if i % 2 == 0:
            add += dp[i // 2] % p
        dp.append(add % p)
    return dp[k]


k, p = map(int, input().split())
print(get_ents_num_modulo_p(k, p))
