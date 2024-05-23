def min_energy(n, coords):
    if n == 1:
        return 0
    if n == 2:
        return abs(coords[1] - coords[0])
    dp = [float('inf'), 0]
    for i in range(2, n + 1):
        first = abs(coords[i - 1] - coords[i - 2]) + dp[i - 1]
        second = 3 * abs(coords[i - 1] - coords[i - 3]) + dp[i - 2]
        dp.append(min(first, second))
    return dp[n]


n = int(input())
coords = list(map(int, input().split()))
print(min_energy(n, coords))
