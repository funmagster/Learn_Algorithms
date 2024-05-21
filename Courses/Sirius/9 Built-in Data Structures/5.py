clients = {}
n = int(input())
for _ in range(n):
    command, *args = input().split()
    if command == 'DEPOSIT':
        name, sum = args
        sum = int(sum)
        if name in clients:
            clients[name] += sum
        else:
            clients[name] = sum
    elif command == 'WITHDRAW':
        name, sum = args
        sum = int(sum)
        if name in clients:
            clients[name] -= sum
        else:
            clients[name] = -sum
    elif command == 'BALANCE':
        name = args[0]
        if name in clients:
            print(clients[name])
        else:
            print('ERROR')
    elif command == 'TRANSFER':
        name1, name2, sum = args
        sum = int(sum)
        if name1 in clients:
            clients[name1] -= sum
        else:
            clients[name1] = -sum
        if name2 in clients:
            clients[name2] += sum
        else:
            clients[name2] = sum
    elif command == 'INCOME':
        p = int(args[0])
        for client in clients:
            if clients[client] > 0:
                clients[client] += clients[client] * p // 100
