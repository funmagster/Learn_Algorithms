def find_dominant_element_with_hach(mas, n):
    dict_elem = {}
    if n == 1:
        return 1
    for elem in mas:
        if elem in dict_elem:
            dict_elem[elem] += 1
            if dict_elem[elem] > n // 2:
                return 1
        else:
            dict_elem[elem] = 1
    return 0


n = int(input())
mas = list(map(int, input().split()))
print(find_dominant_element_with_hach(mas, n))
