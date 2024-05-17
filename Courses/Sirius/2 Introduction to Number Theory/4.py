def set_home(a, b, d):
    a_b = a + b
    mid = a_b // 2
    dist = min(mid % d, d - mid % d)
    if a_b % 2 == 0:
        return mid, dist
    else:
        mid_1 = mid + 1
        dist_1 = min(mid_1 % d, d - mid_1 % d)
        if dist < dist_1:
            return mid, dist
        else:
            return mid_1, dist_1


a, b, d = map(int, input().split())
print(*set_home(a, b, d))
