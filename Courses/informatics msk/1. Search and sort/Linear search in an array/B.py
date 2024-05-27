# 1
def is_in(n, mas, x):
    for i in range(n):
        if mas[i] == x:
            return "YES"
    return "NO"


n = int(input())
mas = list(map(int, input().split()))
x = int(input())
print(is_in(n, mas, x))

# 2
# n = int(input())
# mas = list(map(int, input().split()))
# x = int(input())
# print(('NO', 'YES')[x in mas])
