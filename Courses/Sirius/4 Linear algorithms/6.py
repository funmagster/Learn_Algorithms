def max_len(n, a):
    pr = [0] * (n + 1)
    for i in range(1, n + 1):
        pr[i] = (pr[i - 1] + a[i - 1]) % 3

    mod_0 = -1
    mod_1 = -1
    mod_2 = -1
    start, end = 0, 0
    max_len = 0

    for i in range(n):
        if pr[i + 1] == 0:
            if mod_0 == -1:
                mod_0 = i
            if i + 1 > max_len:
                start = 0
                end = i
                max_len = i + 1
        elif pr[i + 1] == 1:
            if mod_1 == -1:
                mod_1 = i
            elif i - mod_1 > max_len:
                start = mod_1 + 1
                end = i
                max_len = i - mod_1
        elif pr[i + 1] == 2:
            if mod_2 == -1:
                mod_2 = i
            elif i - mod_2 > max_len:
                start = mod_2 + 1
                end = i
                max_len = i - mod_2

    if max_len == 0:
        return [-1]
    return start + 1, end + 1


n = int(input())
a = list(map(int, input().split()))
result = max_len(n, a)
print(*result)
