class Queue:
    def __init__(self):
        self.stack_1 = []
        self.stack_2 = []

    def push(self, n):
        self.stack_1.append(n)
        print('ok')

    def pop(self):
        if not self.stack_2:
            while self.stack_1:
                self.stack_2.append(self.stack_1.pop())
        if self.stack_2:
            print(self.stack_2.pop())
        else:
            print('error')

    def front(self):
        if len(self.stack_2):
            print(self.stack_2[-1])
        elif len(self.stack_1):
            print(self.stack_1[0])
        else:
            print('error')

    def size(self):
        print(len(self.stack_1) + len(self.stack_2))

    def clear(self):
        self.stack_1 = []
        self.stack_2 = []
        print('ok')

    def exit(self):
        print('bye')


go = True
q = Queue()
while go:
    command, *arg = input().split()
    if command == 'size':
        q.size()
    elif command == 'pop':
        q.pop()
    elif command == 'push':
        q.push(arg[0])
    elif command == 'front':
        q.front()
    elif command == 'clear':
        q.clear()
    elif command == 'exit':
        q.exit()
        go = False
