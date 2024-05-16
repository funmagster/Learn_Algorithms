def bin_search(elem, a, n):
    l = -1
    r = n
    while r - l > 1:
        mid = (r + l) // 2
        if a[mid] < elem:
            l = mid
        else:
            r = mid
    return r


def get_answer(n, a, q):
    answer = []
    for question in q:
        answer.append(bin_search(question, a, n))
    return answer


n = int(input())
a = sorted(list(map(int, input().split())))
m = int(input())
q = list(map(int, input().split()))
print(*get_answer(n, a, q))
