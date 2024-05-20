def find_list(n, k):
    if n == 1:
        return [1]
    answer = list(range(n, 0, -1))
    k_sum = n * (n - 1) // 2 - k
    if k_sum == 0:
        return answer
    while n > 0:
        for j in range(n - 1):
            if answer[j] > answer[j + 1]:
                k_sum -= 1
                answer[j + 1], answer[j] = answer[j], answer[j + 1]
                if k_sum == 0:
                    return answer
        n -= 1
    return answer


n, k = map(int, input().split())
print(*find_list(n, k))
