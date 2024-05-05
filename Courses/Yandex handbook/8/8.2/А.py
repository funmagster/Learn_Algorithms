def change(money):
    table = [0]
    for i in range(1, money + 1):
        res = table[i - 1]
        if i - 3 >= 0:
            res = min(res, table[i - 3])
        if i - 4 >= 0:
            res = min(res, table[i - 4])
        table.append(1 + res)
    return table[-1]


money = int(input())
print(change(money))
