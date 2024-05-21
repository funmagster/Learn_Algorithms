def can_correct(n, train):
    way_2 = [0]
    impasse = []
    for i in range(n):
        while len(impasse) and impasse[-1] == way_2[-1] + 1:
            way_2.append(impasse.pop())
        if train[i] == way_2[-1] + 1:
            way_2.append(train[i])
        else:
            impasse.append(train[i])
    while len(impasse) and impasse[-1] == way_2[-1] + 1:
        way_2.append(impasse.pop())
    if way_2[-1] == n:
        return 'YES'
    return 'NO'


n = int(input())
train = list(map(int, input().split()))
print(can_correct(n, train))
