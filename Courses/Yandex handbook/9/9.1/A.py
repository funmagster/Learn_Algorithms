q = int(input())
mas = []
for _ in range(q):
    request, *body = map(int, input().split())
    if request == 1:
        mas.insert(body[0], body[1])
    elif request == 2:
        print(mas[body[0] - 1])
    elif request == 3:
        mas.pop(body[0] - 1)
