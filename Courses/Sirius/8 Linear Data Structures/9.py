from collections import deque


class Deque:
    def __init__(self):
        self.deq = deque([])

    def push_front(self, n):
        self.deq.appendleft(n)
        print('ok')

    def push_back(self, n):
        self.deq.append(n)
        print('ok')

    def pop_front(self):
        if self.check():
            print(self.deq.popleft())
        else:
            print('error')

    def pop_back(self):
        if self.check():
            print(self.deq.pop())
        else:
            print('error')

    def front(self):
        if self.check():
            print(self.deq[0])
        else:
            print('error')

    def back(self):
        if self.check():
            print(self.deq[-1])
        else:
            print('error')

    def size(self):
        print(len(self.deq))

    def clear(self):
        self.deq = deque([])
        print('ok')

    def exit(self):
        print('bye')

    def check(self):
        return len(self.deq) > 0


deq = Deque()
go = True
while go:
    command, *arg = input().split()
    if command == 'size':
        deq.size()
    elif command == 'pop_back':
        deq.pop_back()
    elif command == 'pop_front':
        deq.pop_front()
    elif command == 'push_front':
        deq.push_front(arg[0])
    elif command == 'push_back':
        deq.push_back(arg[0])
    elif command == 'back':
        deq.back()
    elif command == 'front':
        deq.front()
    elif command == 'clear':
        deq.clear()
    elif command == 'exit':
        deq.exit()
        go = False
