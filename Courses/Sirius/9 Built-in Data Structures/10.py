def get_line(n, coords):
    x, y = set(), set()
    for i in range(n - 1):
        if coords[i + 1][0] == coords[i][0] and coords[i + 1][1] > coords[i][1]:
            y.add(coords[i][1] + 1)
        else:
            x.add(coords[i][0] + 1)
    return x, y


n = int(input())
coords = sorted(
    [tuple(map(int, input().split())) for _ in range(n)]
)

x, y = get_line(n, coords)
print(len(x) + len(y))
for line_y in y:
    print(f'y {line_y}')
for line_x in x:
    print(f'x {line_x}')
