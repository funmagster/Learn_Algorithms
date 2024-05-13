q = int(input())
stack = []
for _ in range(q):
    request, *body = map(int, input().split())
    if request == 1:
        stack.append(body[0])
    elif request == 2:
        if stack:
            stack.pop()
    if stack:
        print(stack[-1])
    else:
        print(-1)
