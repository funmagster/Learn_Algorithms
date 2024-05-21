class Stack:
    def __init__(self):
        self.stack = []

    def push(self, n):
        self.stack.append(n)
        print('ok')

    def back(self):
        if self.is_filled():
            print(self.stack[-1])
        else:
            print('error')

    def size(self):
        print(len(self.stack))

    def clear(self):
        self.stack = []
        print('ok')

    def pop(self):
        if self.is_filled():
            elem = self.stack.pop()
            print(elem)
        else:
            print('error')

    def is_filled(self):
        return len(self.stack) > 0

    def exit(self):
        print('bye')


stack = Stack()
go = True
while go:
    command, *arg = input().split()
    if command == 'size':
        stack.size()
    elif command == 'pop':
        stack.pop()
    elif command == 'push':
        stack.push(arg[0])
    elif command == 'back':
        stack.back()
    elif command == 'clear':
        stack.clear()
    elif command == 'exit':
        stack.exit()
        go = False
