def find_three_dimensional_elements(mas, n):
    count = 0
    dict_elem = {}
    if n == 3:
        return int(mas[0] != mas[1] and mas[0] != mas[2] and mas[1] != mas[0])
    elif n < 5:
        return 0
    for elem in mas:
        if elem in dict_elem:
            dict_elem[elem] += 1
            if dict_elem[elem] == n // 4 + 1:
                count += 1
        else:
            dict_elem[elem] = 1
    return int(count == 3)


n = int(input())
mas = list(map(int, input().split()))
print(find_three_dimensional_elements(mas, n))
