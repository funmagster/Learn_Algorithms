# Тип 1

# Для 19-ричной - "0123456789ABCDEFGHI"

# result_search = []
# a = '0123456789ABC'
# for x in a:
#     for y in a:
#         t = int('8' + x + '78' + y, 13) + int('79' + x + y + '7', 18)
#         if t % 9 == 0:
#             result_search.append(t)
# if result_search:
#     print(min(result_search) // 9)

# Тип 2

BASE = 19
for num in range(15):
    a = list(reversed([7, 8, num, 7, 9, 6, 4, 3]))
    b = list(reversed([2, 5, num, 4, 3]))
    c = list(reversed([6, 3, num, 5]))
    for i in range(8):
        a[i] = a[i] * BASE ** i
    for i in range(5):
        b[i] = b[i] * BASE ** i
    for i in range(4):
        c[i] = c[i] * BASE ** i
    if (sum(a) + sum(b)+ sum(c)) % 18 == 0:
        print((sum(a) + sum(b)+ sum(c)) // 18)
        break
