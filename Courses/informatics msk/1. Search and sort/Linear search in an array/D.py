def count_ind(n, mas, x):
    answer = []
    for ind in range(n):
        if mas[ind] == x:
            answer.append(ind + 1)
    return answer


n = int(input())
mas = list(map(int, input().split()))
x = int(input())
print(*count_ind(n, mas, x))
