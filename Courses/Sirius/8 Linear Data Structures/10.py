from collections import deque


n = int(input())
deq_1 = deque([])
deq_2 = deque([])
for _ in range(n):
    op, *goblin = input().split()
    if op == '+':
        deq_2.append(goblin[0])
    elif op == '*':
        deq_2.appendleft(goblin[0])
    else:
        print(deq_1.popleft())
    if len(deq_2) - len(deq_1) > 0:
        deq_1.append(deq_2.popleft())
