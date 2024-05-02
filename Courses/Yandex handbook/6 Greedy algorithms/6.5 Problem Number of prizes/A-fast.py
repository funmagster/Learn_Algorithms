def calk_k(n):
    return int((-1 + (1 + 8*n)**0.5) // 2)


n = int(input())
print(calk_k(n))
