def get_fact_mas(n):
    fact_mas = [1, 1]
    for i in range(2, n+1):
        fact_mas.append(fact_mas[i-1]*i)
    return fact_mas


def C_with_repeat(n, k):
    if n == 0:
        return 1
    if k > n:
        return 0
    fact_mas = get_fact_mas(n)
    return int(fact_mas[n] / (fact_mas[k] * fact_mas[n-k]))


n, k = map(int, input().split())
print(C_with_repeat(n+k-1, k))