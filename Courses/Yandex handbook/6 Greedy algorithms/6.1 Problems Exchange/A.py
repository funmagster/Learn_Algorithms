nominal_set = set()


def spread_out(nominal):
    global nominal_set
    nominal_set.add(nominal)
    if nominal[0] != 0:
        if (nominal[0] - 1, nominal[1] + 2, nominal[2]) not in nominal_set:
            spread_out((nominal[0] - 1, nominal[1] + 2, nominal[2]))
    if nominal[1] != 0:
        if (nominal[0], nominal[1] - 1, nominal[2] + 5) not in nominal_set:
            spread_out((nominal[0], nominal[1] - 1, nominal[2] + 5))


money = int(input())
start_nominal = (money // 10, (money % 10) // 5, money % 5)
spread_out(start_nominal)

print(len(nominal_set))
for i in nominal_set:
    print(sum(i), end=' ')
    print(f"{'10 '*i[0]}{'5 '*i[1]}{'1 '*i[2]}".rstrip())
