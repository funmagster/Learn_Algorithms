def merge(list1, list2, n1, n2):
    final_list = []
    a, b = 0, 0
    while a < n1 and b < n2:
        if list1[a] < list2[b]:
            final_list.append(list1[a])
            a += 1
        else:
            final_list.append(list2[b])
            b += 1
    if a == n1:
        for i in range(b, n2):
            final_list.append(list2[i])
    else:
        for i in range(a, n1):
            final_list.append(list1[i])
    return final_list


def MergeSort(mas, n) -> list:
    if n == 1:
        return mas
    first_len, second_len = n//2, n - n//2
    firs_half = MergeSort(mas[0:first_len], first_len)
    second_half = MergeSort(mas[first_len:], second_len)
    return merge(firs_half, second_half, first_len, second_len)


n = int(input())
mas = list(map(int, input().split()))
print(*MergeSort(mas, n))