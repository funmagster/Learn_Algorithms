def max_value(expr):
    n = len(expr) // 2
    max_vals = [[-float('inf')] * (n + 1) for _ in range(n + 1)]
    min_vals = [[float('inf')] * (n + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        min_vals[i][i] = int(expr[2 * i])
        max_vals[i][i] = int(expr[2 * i])

    for s in range(1, n + 1):
        for l in range(1, n - s + 1):
            r = s + l
            for m in range(l, r):
                op = expr[2 * m + 1]
                first_max = max_vals[l][m]
                second_max = max_vals[m + 1][r]
                first_min = min_vals[l][m]
                second_min = min_vals[m + 1][r]
                if op == '+':
                    a = first_min + second_min
                    b = first_min + second_max
                    c = first_max + second_min
                    d = first_max + second_max
                elif op == '-':
                    a = first_min - second_min
                    b = first_min - second_max
                    c = first_max - second_min
                    d = first_max - second_max
                elif op == '*':
                    a = first_min * second_min
                    b = first_min * second_max
                    c = first_max * second_min
                    d = first_max * second_max
                min_vals[l][r] = min(min_vals[l][r], a, b, c, d)
                max_vals[l][r] = min(max_vals[l][r], a, b, c, d)

    return max_vals[0][n]


expression = input()
print(max_value(expression))
