def visibility_to_left(mas, n):
    pr = [0]
    for i in range(1, n):
        c = 0
        for j in range(i - 1, -1, -1):
            if mas[i] > mas[j]:
                c += 1
            else:
                break
        pr.append(c)
    return pr


n = int(input())
mas = list(map(int, input().split()))
print(*visibility_to_left(mas, n))
