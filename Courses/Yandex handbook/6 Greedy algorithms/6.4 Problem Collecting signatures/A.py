def segments_cover(intervals, n):
    r_m = intervals[0][1]
    answer = [r_m]
    for i in range(1, n):
        if intervals[i][0] > r_m:
            answer.append(intervals[i][1])
            r_m = intervals[i][1]
    return answer


n = int(input())
intervals = sorted(
    [tuple(map(int, input().split())) for _ in range(n)],
    key=lambda x: x[1]
)
answer = segments_cover(intervals, n)
print(len(answer))
print(*answer, sep=' ')
