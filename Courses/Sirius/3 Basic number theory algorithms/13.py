def get_prime(n):
    prime = [True] * (n + 1)
    prime[0] = prime[1] = False
    prime_ans = []
    for i in range(2, n+1):
        if prime[i]:
            prime_ans.append(i)
            for j in range(i*i, n + 1, i):
                prime[j] = False
    return prime_ans


def find_super_number(A, B):
    answer = set()
    prime = get_prime(B)
    for i in range(len(prime) - 1):
        for j in range(i, len(prime)):
            sums = prime[i] + prime[j]
            if A <= sums <= B:
                answer.add(sums)
    return answer


A, B = map(int, input().split())
print(*find_super_number(A, B), sep='\n')