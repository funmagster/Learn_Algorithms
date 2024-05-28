def binary_search(n, mas, x):
    l = 0
    r = n - 1
    while r - l > 1:
        mid = (r + l) // 2
        if mas[mid] > x:
            r = mid
        else:
            l = mid
    if abs(mas[r] - x) >= abs(mas[l] - x):
        return mas[l]
    return mas[r]


def find_nearest(n, k, mas, q):
    answer = []
    for i in range(k):
        answer.append(binary_search(n, mas, q[i]))
    return answer


n, k = map(int, input().split())
mas = list(map(int, input().split()))
q = list(map(int, input().split()))
print(*find_nearest(n, k, mas, q), sep='\n')
