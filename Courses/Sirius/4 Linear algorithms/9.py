def pick_up_clothes(n, t_shirts, m, trousers):
    i_best, i = 0, 0
    j_best, j = 0, 0
    while i < n and j < m:
        if abs(t_shirts[i] - trousers[j]) < abs(t_shirts[i_best] - trousers[j_best]):
            j_best, i_best = j, i
        if t_shirts[i] == trousers[j]:
            return t_shirts[i], trousers[j]
        if t_shirts[i] > trousers[j]:
            j += 1
        else:
            i += 1
    return t_shirts[i_best], trousers[j_best]


n = int(input())
t_shirts = list(map(int, input().split()))
m = int(input())
trousers = list(map(int, input().split()))
print(*pick_up_clothes(n, t_shirts, m, trousers))
