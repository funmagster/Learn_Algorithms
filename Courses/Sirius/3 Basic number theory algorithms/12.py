def factorization(n):
    d = {i: 0 for i in range(2, n+1)}
    for i in range(2, n+1):
        j = 2
        n_i = i
        while j * j <= n_i:
            cnt = 0
            while n_i % j == 0:
                n_i //= j
                cnt += 1
            d[j] += cnt
            j += 1
        if n_i > 1:
            d[n_i] += 1
    return d


def get_count_div_fact(n):
    answer = 1
    d = factorization(n)
    for num in d:
        if d[num] > 0:
            answer *= (d[num] + 1)
    return answer


n = int(input())
print(get_count_div_fact(n))
