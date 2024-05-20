def merge(first_half, n1, second_half, n2):
    res, i, j = [], 0, 0    
    while i < n1 and j < n2:
        if first_half[i] <= second_half[j]:
            res.append(first_half[i])
            i += 1
        else:
           res.append(second_half[j])
           j += 1
    res.extend(first_half[i:])
    res.extend(second_half[j:])
    return res


def merge_sort(a, n):
    if n <= 1:
        return a
    mid = n // 2
    first_half = a[:mid]
    second_half = a[mid:]
    return merge(first_half, mid, second_half, n - mid)


n = int(input())
a = list(map(int, input().split()))
print(*merge_sort(a, n))