n1 = int(input())
set_1 = set(map(int, input().split()))
n2 = int(input())
set_2 = set(map(int, input().split()))
res_set = sorted(set_1 ^ set_2)
print(len(res_set))
print(*res_set)
