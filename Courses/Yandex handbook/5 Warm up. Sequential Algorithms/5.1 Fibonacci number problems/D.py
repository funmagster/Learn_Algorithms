def get_Fn_mod_m(n, m):
    a, b = 0, 1
    if n < 2:
        return n
    else:
        for i in range(2, n + 1):
            a, b = b, (a + b) % m
        return b


n = int(input())
f_n2 = get_Fn_mod_m((n + 2) % 60, 10)
if f_n2 == 0:
    print(9)
else:
    print(f_n2 - 1)
