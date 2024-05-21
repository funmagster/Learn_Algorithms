def is_correct(seq):
    stack = []
    for bracket in seq:
        if bracket in '([{':
            stack.append(bracket)
        elif len(stack) > 0:
            if bracket == ')':
                if stack[-1] == '(':
                    stack.pop()
                else:
                    return 'no'
            if bracket == ']':
                if stack[-1] == '[':
                    stack.pop()
                else:
                    return 'no'
            if bracket == '}':
                if stack[-1] == '{':
                    stack.pop()
                else:
                    return 'no'
        else:
            return 'no'
    if len(stack) == 0:
        return 'yes'
    return 'no'


seq = input()
print(is_correct(seq))
