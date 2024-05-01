def count_max_interval(n, reservation):
    max_interval = 0
    now = 0
    while now < n:
        r_win = reservation[now][-1]
        for i in range(now + 1, n):
            if reservation[i][0] <= r_win:
                max_interval += 1
                now += 1
            else:
                break
        now += 1
    return n - max_interval


n = int(input())
reservation = [tuple(map(int, input().split())) for _ in range(n)]
reservation.sort(key=lambda x: (x[1], x[0]))
print(count_max_interval(n, reservation))
