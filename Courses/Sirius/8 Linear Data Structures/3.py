def calk(seq):
    stack = []
    for i in seq.split():
        if i.isdigit():
            stack.append(int(i))
        else:
            a, b = stack.pop(), stack.pop()
            if i == '+':
                stack.append(a + b)
            elif i == '-':
                stack.append(b - a)
            elif i == '*':
                stack.append(a * b)
    return stack[0]


seq = input()
print(calk(seq))
