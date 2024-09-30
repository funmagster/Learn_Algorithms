from itertools import product


def ok(x, y, z, w):
    return 0


print('x\ty\tz\tw')
for x, y, z, w in product((0, 1), repeat=4):
    f = ok(x, y, x, w)
    if f == 0:
        print(x, y, z, w, sep='\t')
