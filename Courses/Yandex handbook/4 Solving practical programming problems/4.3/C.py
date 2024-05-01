import heapq

n = int(input())
mas = list(map(int, input().split()))
max_3 = heapq.nlargest(3, mas)
min_2 = heapq.nsmallest(2, mas)
first_dot = max_3[0] * max_3[1] * max_3[2]
second_dot = max(max_3) * min_2[0] * min_2[1]
print(max(first_dot, second_dot))
