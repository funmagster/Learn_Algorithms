def calc_radical(a, n):
    l = 0
    if a < 1:
        r = 1
    else:
        r = a
    while r - l > 1e-7:
        mid = (l + r) / 2
        if mid ** n >= a:
            r = mid
        else:
            l = mid
    return r


a = float(input())
n = int(input())
print(calc_radical(a, n))
