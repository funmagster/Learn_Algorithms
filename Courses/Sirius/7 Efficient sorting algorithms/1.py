def max_number(s):
    cnt = [0] * 10
    for chars in s:
        if chars.isdigit():
            cnt[int(chars)] += 1
    flag = False
    ans = []
    for num in range(9, 0, -1):
        if cnt[num] != 0:
            flag = True
        ans.extend([str(num)]*cnt[num])
    if not flag:
        if cnt[0] == 0:
            return -1
        return 0
    return ''.join(ans + [str(0)]*cnt[0])


s = input()
print(max_number(s))
