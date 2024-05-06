def call_dist(dot1, dot2):
    return ((dot1[0] - dot2[0])**2 + (dot1[1] - dot2[1])**2)**0.5


def calk_min_dist_slow(cords, start, end):
    d_min = float('inf')
    for i in range(start, end + 1):
        j = i + 1
        while j < end and j < i + 7:
            d_min = min(d_min, call_dist(cords[i], cords[j]))
            j += 1
    return d_min


def bin_search_elem(cords, start, end, d):
    l = start - 1
    r = end - 1
    while r - l > 1:
        mid = (l + r) // 2
        if cords[mid][0] < d:
            l = mid
        else:
            r = mid
    return r


def calk_min_dist(n, cords, start):
    if n == 1:
        return float('inf')
    if n == 2:
        return call_dist(cords[start], cords[start + 1])

    start_l, start_r = start, start + n // 2
    d_min = min(
        calk_min_dist(n // 2, cords, start_l),
        calk_min_dist(n - n // 2, cords, start_r)
    )
    d_1 = bin_search_elem(cords, start_l, start_r, cords[start_r - 1][0] - d_min)
    d_2 = bin_search_elem(cords, start_r, start_l + n, cords[start_r][0] + d_min)
    d_min = min(
        d_min,
        calk_min_dist_slow(cords, d_1, d_2)
    )
    return d_min


n = int(input())
cords = sorted(
    [tuple(map(int, input().split())) for _ in range(n)],
)
print(round(calk_min_dist(n, cords, 0), 6))
