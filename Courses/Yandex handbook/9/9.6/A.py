from collections import deque

q = int(input())
d = deque([])
for _ in range(q):
    request, *body = map(int, input().split())
    if request == 1:
        d.append(body[0])
    elif request == 2:
        d.popleft()
    if d:
        print(d[0])
    else:
        print(-1)
