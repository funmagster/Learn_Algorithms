def trans_str(s):
    while ('333' in s) or ('999' in s) or ('1111' in s):
        if '333' in s:
            s = s.replace('333', '9', 1)
        elif 0:
            ...
        else:
            s = s.replace('999', '3', 1)
    return d


for cnt in range(3, 10_000 + 1):
    s = '1' + '2'*cnt
    ans = trans_str(s)

    sums = 0
    for symb in ans:
        sums += int(symb)

    if sums == 22:
        print(i)
        break