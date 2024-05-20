def find_last_number_fact(n):
    count_2 = 0
    res = 1
    for i in range(1, n+1):
        num = i
        while num % 2 == 0:
            num //= 2
            count_2 += 1
        while num % 5 == 0:
            num //= 5
            count_2 -= 1
        res = (res * (num % 10)) % 10
    for i in range(count_2):
        res = (res * 2) % 10
    return res


n = int(input())
print(find_last_number_fact(n))