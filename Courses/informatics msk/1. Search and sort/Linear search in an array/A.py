# 1
def count(mas, x):
    cnt = 0
    for elem in mas:
        if elem == x:
            cnt += 1
    return cnt


n = int(input())
mas = list(map(int, input().split()))
x = int(input())
print(count(mas, x))


# 2
# n = int(input())
# mas = list(map(int, input().split()))
# x = int(input())
# print(mas.count(x))
