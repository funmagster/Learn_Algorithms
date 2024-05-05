def calk(n):
    table = [0, 1, 1, 1]
    if n < 4:
        return table[n], [1, n]
    for i in range(4, n+1):
        k = table[i - 1]
        if i % 2 == 0:
            k = min(k, table[i // 2])
        if i % 3 == 0:
            k = min(k, table[i // 3])
        table.append(k + 1)
    k_return = table[-1]
    answer = [n]
    i = n
    while i > 1:
        if i % 3 == 0 and table[i // 3] == table[i] - 1:
            i = i // 3
        elif i % 2 == 0 and table[i // 2] == table[i] - 1:
            i = i // 2
        elif i < 4:
            answer.append(1)
            break
        else:
            i -= 1
        answer.append(i)

    return k_return, answer


n = int(input())
k_return, answer = calk(n)
print(k_return)
for i in range(len(answer) - 1, 0, -1):
    print(answer[i], end=' ')
print(answer[0], end='')
