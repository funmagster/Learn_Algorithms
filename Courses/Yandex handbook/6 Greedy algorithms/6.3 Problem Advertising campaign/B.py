def get_max_profit(days, ad, k):
    profit = 0
    i = 0
    while days != 0 and i < k:
        days_ad = min(days, ad[i][1])
        profit += ad[i][0] * days_ad
        days -= days_ad
        i += 1
    return profit


n, k, w = map(int, input().split())
ad = sorted(
    [tuple(map(int, input().split())) for _ in range(k)],
    key=lambda x: -x[0]
)
print(get_max_profit(n*w, ad, k))
