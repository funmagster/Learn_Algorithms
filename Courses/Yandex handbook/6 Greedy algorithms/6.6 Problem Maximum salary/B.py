n, k = map(int, input().split())
skills = list(map(int, input().split()))
count_min = 0
count_win = 0
for robo in range(n):
    if robo != k - 1 and skills[robo] < skills[k - 1]:
        count_min += 1
while count_min > 0:
    if count_min == 1:
        count_win += 1
        break
    if n % 2 == 0:
        count_win += 1
        count_min = count_min // 2 - 1 * ((n-count_min-1) % 2)
        n = n // 2
    else:
        count_win += 1
        count_min = 1 + (count_min - 1) // 2 - 1 * ((n-count_min-1) % 2)
        n = n // 2 + 1
print(count_win)
