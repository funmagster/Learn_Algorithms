from collections import deque


def comp(a, b):
    if (a, b) == ('0', '9'):
        return True
    elif (a, b) == ('9', '0'):
        return False
    return a > b


def drunk_game(a, b):
    cnt = 0
    while len(a) > 0 and len(b) > 0 and cnt <= 1_000_000:
        one = a.popleft()
        two = b.popleft()
        if comp(one, two):
            a.append(one)
            a.append(two)
        else:
            b.append(one)
            b.append(two)
        cnt += 1
    if len(a) == 0:
        return 'second', cnt
    elif len(b) == 0:
        return 'first', cnt
    return [cnt]


a, b = deque(input().split()), deque(input().split())
print(*drunk_game(a, b), sep=' ')
