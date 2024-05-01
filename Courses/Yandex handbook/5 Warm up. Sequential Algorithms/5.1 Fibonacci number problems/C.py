def pisano_period(m):
    current = 0
    next = 1
    period = 0
    while True:
        oldNext = next
        next = (current + next) % m
        current = oldNext
        period = period + 1
        if current == 0 and next == 1:
            return period


def get_Fn_mod_m(n, m):
    a, b = 0, 1
    if n < 2:
        return n
    else:
        for i in range(2, n + 1):
            a, b = b, (a + b) % m
        return b


n, m = map(int, input().split())
period = pisano_period(m)
print(get_Fn_mod_m(n % period, m))
