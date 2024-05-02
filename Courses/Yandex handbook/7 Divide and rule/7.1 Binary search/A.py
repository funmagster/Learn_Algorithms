def bin_search(n, mas, elem):
    l = -1
    r = n - 1
    while r - l > 1:
        mid = (l + r) // 2
        if mas[mid] < elem:
            l = mid
        else:
            r = mid
    if mas[r] == elem:
        return r
    return -1


n = int(input())
mas = list(map(int, input().split()))
elem = int(input())
print(bin_search(n, mas, elem))
