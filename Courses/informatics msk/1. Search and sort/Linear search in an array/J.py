def find_out_points(n, mas):
    max_elem = mas[0]
    max_max_elem = mas[1]
    if max_elem > max_max_elem:
        max_elem, max_max_elem = max_max_elem, max_elem
    for i in range(2, n):
        if mas[i] > max_max_elem:
            max_elem = max_max_elem
            max_max_elem = mas[i]
        elif mas[i] > max_elem and mas[i] != max_max_elem:
            max_elem = mas[i]
    return max_elem


n = int(input())
mas = list(map(int, input().split()))
print(find_out_points(n, mas))
