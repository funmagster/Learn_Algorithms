def R(n, m):
    if n % 2 == 0 and m % 2 == 0:
        return 'Loose'
    return 'Win'


n, m = map(int, input().split())
print(R(n, m))