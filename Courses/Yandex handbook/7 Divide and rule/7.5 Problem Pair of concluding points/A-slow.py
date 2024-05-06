def call_dist(dot1, dot2):
    return ((dot1[0] - dot2[0])**2 + (dot1[1] - dot2[1])**2)**0.5


def calk_min_dist(n, cords):
    d_min = float('inf')
    for i in range(n - 1):
        for j in range(i+1, n):
            d_min = min(d_min, call_dist(cords[i], cords[j]))
    return round(d_min, 6)


n = int(input())
cords = sorted(
    [tuple(map(int, input().split())) for _ in range(n)],
)
print(calk_min_dist(n, cords))
