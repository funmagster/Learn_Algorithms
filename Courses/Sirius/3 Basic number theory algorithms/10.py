from collections import deque
from math import gcd


def get_div(n):
    div_1 = []
    div_2 = deque([])
    i = 2
    while i * i < n:
        if n % i == 0:
            div_1.append(i)
            div_2.appendleft(n // i)
        i += 1
    if i*i == n:
        div_1.append(i)
    return div_1 + list(div_2)


def count_ab(n):
    if n == 1:
        return 0, [1]
    div = get_div(n)
    LEN_DIV = len(div)
    count = LEN_DIV + 1
    for i in range(LEN_DIV - 1):
        for j in range(i + 1, LEN_DIV):
            if div[i] * div[j] > n:
                break
            if gcd(div[i], div[j]) == 1:
                count += 1
    return count


n = int(input())
print(count_ab(n))
