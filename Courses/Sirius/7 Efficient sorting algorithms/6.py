def sum_number(num):
    cnt = 0
    for i in num:
        cnt += int(i)
    return cnt


n = int(input())
mas = sorted(
    input().split(),
    key=lambda x: -sum_number(x)
)
print(*mas)
