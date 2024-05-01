n = int(input())
if n <= 6:
    print('No')
else:
    print("Yes")
    print(*[i for i in range(n, 0, -1)])
