def merge(list1, list2, n1, n2):
    sorted_list = []
    inversions = 0
    l_ind, r_ind = 0, 0
    while l_ind < n1 and r_ind < n2:
        l = list1[l_ind]
        r = list2[r_ind]
        if l <= r:
            sorted_list.append(l)
            l_ind += 1
        else:
            sorted_list.append(r)
            r_ind += 1
            inversions += n1 - l_ind
    if l_ind < n1:
        for i in range(l_ind, n1):
            sorted_list.append(list1[i])
    else:
        for i in range(r_ind, n2):
            sorted_list.append(list2[i])
    return sorted_list, inversions


def count_inversions(n, mas):
    if n == 1:
        return mas, 0
    l_half, r_half = mas[0:n//2], mas[n//2:]
    l_half, leftInv = count_inversions(n // 2, l_half)
    r_half, rightInv = count_inversions(n - n // 2, r_half)
    sorted_list, splitInv = merge(l_half, r_half, n // 2, n - n//2)
    return sorted_list, leftInv + rightInv + splitInv


n = int(input())
mas = list(map(int, input().split()))
print(count_inversions(n, mas)[1])
