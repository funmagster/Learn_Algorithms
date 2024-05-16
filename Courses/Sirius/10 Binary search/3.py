def bin_search(elem, a, n):
    l = 0
    r = n - 1
    while r - l > 1:
        mid = (r + l) // 2
        if a[mid] < elem:
            l = mid
        else:
            r = mid
    if elem - a[l] <= a[r] - elem:
        return a[l]
    return a[r]


def get_answer(n, a, q):
    answer = []
    for question in q:
        answer.append(bin_search(question, a, n))
    return answer


n, k = map(int, input().split())
a = sorted(list(map(int, input().split())))
q = list(map(int, input().split()))
print(*get_answer(n, a, q), sep='\n', end='')
