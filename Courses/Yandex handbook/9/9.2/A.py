q = int(input())
my_set = set()
for _ in range(q):
    request, x = map(int, input().split())
    if request == 1:
        my_set.add(x)
    if request == 2:
        if x in my_set:
            print(1)
        else:
            print(0)
