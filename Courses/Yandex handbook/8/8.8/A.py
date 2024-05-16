def evaluate_expression(operands, operators):
    mins = [[float('inf')] * len(operands) for _ in range(len(operands))]
    maxs = [[-float('inf')] * len(operands) for _ in range(len(operands))]

    for i in range(len(operands)):
        mins[i][i] = operands[i]
        maxs[i][i] = operands[i]

    for s in range(1, len(operands)):
        for l in range(len(operands) - s):
            r = l + s
            for m in range(l, r):
                if operators[m] == '+':
                    a = mins[l][m] + mins[m+1][r]
                    b = mins[l][m] + maxs[m+1][r]
                    c = maxs[l][m] + mins[m+1][r]
                    d = maxs[l][m] + maxs[m+1][r]
                elif operators[m] == '-':
                    a = mins[l][m] - mins[m+1][r]
                    b = mins[l][m] - maxs[m+1][r]
                    c = maxs[l][m] - mins[m+1][r]
                    d = maxs[l][m] - maxs[m+1][r]
                elif operators[m] == '*':
                    a = mins[l][m] * mins[m+1][r]
                    b = mins[l][m] * maxs[m+1][r]
                    c = maxs[l][m] * mins[m+1][r]
                    d = maxs[l][m] * maxs[m+1][r]
                mins[l][r] = min(mins[l][r], a, b, c, d)
                maxs[l][r] = max(maxs[l][r], a, b, c, d)

    return maxs[0][-1]


s = input()
operands = []
operators = []
for i in range(len(s)):
    if i % 2 == 0:
        operands.append(int(s[i]))
    else:
        operators.append(s[i])

print(evaluate_expression(operands, operators))
