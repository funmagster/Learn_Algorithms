from math import gcd


def max_count_num(n, a):
    count_m = 0
    for i in range(n):
        count = 0
        gcd_num = a[i]
        if n - i < count_m:
            return count_m
        for j in range(i, n):
            count += 1
            gcd_num = gcd(gcd_num, a[j])
            if gcd_num == 1:
                break
            a[j] //= gcd_num
            count_m = max(count_m, count)
    return count_m


n = int(input())
a = list(map(int, input().split()))
print(max_count_num(n, a))