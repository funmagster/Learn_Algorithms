def is_good(x, n, mas):
    answer = []
    for i in range(n):
        for j in range(n):
            if mas[j][i] == x:
                answer.append('YES')
                break
        else:
            answer.append('NO')
    return answer


x = int(input())
n = int(input())
mas = [[int(i) for i in input().split()] for _ in range(n)]
print(*is_good(x, n, mas), sep='\n')
