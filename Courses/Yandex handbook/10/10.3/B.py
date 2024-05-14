from collections import deque


def min_operations(X, Y):
    queue = deque([(X, 0)])
    visited = set()

    while queue:
        num, ops = queue.popleft()

        if num == Y:
            return ops

        if num in visited:
            continue

        visited.add(num)

        for i in range(10):
            new_num = num + i
            if 0 < new_num <= Y:
                queue.append((new_num, ops + 1))

            new_num = num - i
            if 0 < new_num <= Y:
                queue.append((new_num, ops + 1))

            new_num = num * i
            if new_num > 0 and num <= Y or new_num == 0:
                queue.append((new_num, ops + 1))

    return -1


x, y = map(int, input().split())
result = min_operations(x, y)
print(result)
