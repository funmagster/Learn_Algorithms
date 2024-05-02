def count_segments(n, l, dot):
    count = 1
    length = dot[0] + l
    for i in range(1, n):
        if dot[i] > length:
            count += 1
            length = dot[i] + l
    return count


n, l = map(int, input().split())
dot = sorted(list(map(int, input().split())))
print(count_segments(n, l, dot))
