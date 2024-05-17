def k_prime(k):
    prime = [True] * (k*17 + 1)
    if k == 1:
        return 2
    prime[0] = prime[1] = False
    count = 0
    i = 1
    while count < k:
        i += 1
        if not prime[i]:
            continue
        for j in range(i*i, k*17 + 1, i):
            prime[j] = False
        count += 1
    return i


k = int(input())
print(k_prime(k))
