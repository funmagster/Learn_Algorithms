def get_Fn_mod_m(n, m):
    a, b = 0, 1
    if n < 2:
        return n
    else:
        for i in range(2, n + 1):
            a, b = b, (a + b) % m
        return b


def round_dif(a, b):
    return (10 + (a - b)) % 10


def get_last_sum_numb(n):
    f_n2 = get_Fn_mod_m((n + 2) % 60, 10)
    if f_n2 == 0:
        return 9
    else:
        return f_n2 - 1


m, n = map(int, input().split())
print(round_dif(get_last_sum_numb(n), get_last_sum_numb(m-1)))
