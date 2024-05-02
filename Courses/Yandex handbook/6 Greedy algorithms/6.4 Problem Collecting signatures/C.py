def ok(n, l, dot, count_must):
    count = 1
    length = dot[0] + l
    for i in range(1, n):
        if dot[i] > length:
            count += 1
            length = dot[i] + l
    return count <= count_must


def calk_length(n, k, dot):
    l = -1
    r = dot[-1] - dot[0]
    while r - l > 1:
        mid = (r + l) // 2
        if ok(n, mid, dot, k):
            r = mid
        else:
            l = mid
    return r


def calk_sum_length(l, dot):
    sum_length = 0
    length = dot[0] + l
    ind = 0
    for i in range(1, n):
        if dot[i] > length:
            sum_length += dot[i-1] - dot[ind]
            length = dot[i] + l
            ind = i
    sum_length += dot[-1] - dot[ind]
    return sum_length


n, k = map(int, input().split())
dot = sorted(list(map(int, input().split())))
print(calk_sum_length(calk_length(n, k, dot), dot))
