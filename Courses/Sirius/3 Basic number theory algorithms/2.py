def get_min_div(n):
    i = 2
    while i*i <= n:
        if n % i == 0:
            return i
        i += 1
    return n


n = int(input())
print(get_min_div(n))