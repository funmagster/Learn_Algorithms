def l_bin_search(mas, n, elem):
    l = -1
    r = n - 1
    while r - l > 1:
        mid = (l + r) // 2
        if mas[mid] >= elem:
            r = mid
        else:
            l = mid
    if mas[r] == elem:
        return r
    return 0


def r_bin_search(mas, n, elem):
    l = 0
    r = n
    while r - l > 1:
        mid = (l + r) // 2
        if mas[mid] <= elem:
            l = mid
        else:
            r = mid
    if mas[l] == elem:
        return l
    return 0


def count_elems(mas, n, elems):
    answer = []
    for elem in elems:
        l_index = l_bin_search(mas, n, elem)
        r_index = r_bin_search(mas, n, elem)
        if r_index == l_index:
            if mas[r_index] == elem:
                answer.append(1)
            else:
                answer.append(0)
        else:
            answer.append(r_index - l_index + 1)
    return answer


n = int(input())
mas = list(map(int, input().split()))
m = int(input())
elems = list(map(int, input().split()))
print(*count_elems(mas, n, elems))
