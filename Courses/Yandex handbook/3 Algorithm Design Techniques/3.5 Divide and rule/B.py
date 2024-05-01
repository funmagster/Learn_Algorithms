from heapq import heappop, heappush


n = int(input())
mas = []
for i in range(n):
    m = int(input())
    for j in map(int, input().split()):
        heappush(mas, j)
for i in range(len(mas)):
    print(heappop(mas), end=' ')
