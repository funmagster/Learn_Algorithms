def get_count_sum_div(n):
    if n == 1:
        return 1, 1
    sigma0 = 2
    sigma1 = n + 1
    i = 2
    while i*i < n:
        if n % i == 0:
            sigma0 += 2
            sigma1 += i + n // i
        i += 1
    if i*i == n:
        sigma0 += 1
        sigma1 += i
    return sigma0, sigma1


n = int(input())
print(*get_count_sum_div(n))
