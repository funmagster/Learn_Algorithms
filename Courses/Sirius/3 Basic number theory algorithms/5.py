def factorization(n):
    answer = []
    d = 2
    while d*d <= n:
        cnt = 0
        while n % d == 0:
            cnt += 1
            n //= d
        if cnt == 1:
            answer.append(str(d))
        elif cnt > 1:
            answer.append(f'{d}^{cnt}')
        d += 1
    if n > 1:
        answer.append(str(n))
    return '*'.join(answer)


n = int(input())
print(factorization(n))