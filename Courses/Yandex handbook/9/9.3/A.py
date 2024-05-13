q = int(input())
my_d = {}
for _ in range(q):
    request, *body = map(int, input().split())
    if request == 1:
        my_d[body[0]] = body[1]
    elif request == 2:
        if body[0] in my_d:
            print(my_d[body[0]])
        else:
            print(-1)
