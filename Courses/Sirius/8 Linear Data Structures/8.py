stack = []
temp_stack = []
min_stack = []
temp_min_stack = []

n = int(input())

for _ in range(n):
    value = int(input())

    if value != 0:
        stack.append(value)
        if not min_stack or value < min_stack[-1]:
            min_stack.append(value)
        else:
            min_stack.append(min_stack[-1])
    else:
        if not temp_stack:
            while stack:
                element = stack.pop()
                temp_stack.append(element)
                if not temp_min_stack or element < temp_min_stack[-1]:
                    temp_min_stack.append(element)
                else:
                    temp_min_stack.append(temp_min_stack[-1])
            min_stack.clear()

        if not temp_stack:
            print(-1)
        else:
            temp_stack.pop()
            if temp_min_stack:
                min_value = temp_min_stack.pop()
                if min_stack:
                    min_value = min(min_value, min_stack[-1])
                print(min_value)
            else:
                print(-1)
