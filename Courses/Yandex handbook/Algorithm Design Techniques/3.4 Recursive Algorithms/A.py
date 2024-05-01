answer = []
count = 0
def HanoiTowers(n, fromPeg, toPeg):
    global count, answer
    count += 1
    if n == 1:
        answer.append((fromPeg, toPeg))
    else:
        unusedPeg = 6 - fromPeg - toPeg
        HanoiTowers(n-1, fromPeg, unusedPeg)
        answer.append((fromPeg, toPeg))
        HanoiTowers(n-1, unusedPeg, toPeg)


n = int(input())
HanoiTowers(n, 1, 3)
print(count)
for i in answer:
    print(*i)
