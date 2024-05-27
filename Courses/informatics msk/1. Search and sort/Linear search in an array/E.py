# 1
def max_2(n, mas):
    ind_m = 0
    for i in range(1, n):
        if mas[ind_m] < mas[i]:
            ind_m = i
    return mas[ind_m]


n = int(input())
mas = list(map(int, input().split()))
print(max_2(n, mas))

# 2
# n = int(input())
# mas = list(map(int, input().split()))
# print(max(mas))
