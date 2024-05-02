def calk_k(n):
    k = 1
    while k * (k+1) // 2 <= n:
        k += 1
    return k - 1


n = int(input())
print(calk_k(n))
