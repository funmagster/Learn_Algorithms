def get_max_profit(n, clicks, prices):
    profit = 0
    for i in range(n):
        profit += clicks[i]*prices[i]
    return profit


n = int(input())
prices = sorted(list(map(int, input().split())), reverse=True)
clicks = sorted(list(map(int, input().split())), reverse=True)
print(get_max_profit(n, clicks, prices))
