from functools import cmp_to_key


def comp_str(a, b):
    if a + b < b + a:
        return 1
    elif a + b == b + a:
        return 0
    else:
        return -1


n = int(input())
seq = sorted(
    [input() for _ in range(n)],
    key=cmp_to_key(comp_str))
print(''.join(seq))
