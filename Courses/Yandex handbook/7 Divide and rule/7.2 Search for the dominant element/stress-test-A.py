from random import randint
from tqdm import tqdm
import threading


def timeout_handler():
    global mas, n
    print('\nTimeout')
    print(n, *mas)
    exit(0)


def is_dominant_element(dominant, mas, n, start, end):
    count = 0
    for elem_ind in range(start, end):
        if mas[elem_ind] == dominant:
            count += 1
    if count > n // 2:
        return dominant
    return -1


def is_dominant_two_element(first, second, mas, n, start, end):
    count_first = 0
    count_second = 0
    for elem_ind in range(start, end):
        if mas[elem_ind] == first:
            count_first += 1
        elif mas[elem_ind] == second:
            count_second += 1
    if count_first > n // 2:
        return first
    elif count_second > n // 2:
        return second
    return -1


def find_dominant_element(mas, n, start, end):
    if n == 1:
        return mas[start]
    first = find_dominant_element(mas, n // 2, start, start + n // 2)
    second = find_dominant_element(mas, n - n // 2, start + n // 2, start + n)
    if first != -1:
        if second != -1:
            return is_dominant_two_element(first, second, mas, n, start, end)
        else:
            return is_dominant_element(first, mas, n, start, end)
    else:
        return is_dominant_element(second, mas, n, start, end)


def chech_dominant(mas, n):
    if find_dominant_element(mas, n, 0, n) != -1:
        return 1
    return 0

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


def return_mas(n, last_elem):
    if n % 2 == 1:
        return [last_elem]
    else:
        return []


def find_dominant_On(mas, n):
    if n == 1:
        return 1
    if n % 2:
        mas.append(mas[-2])

    new_mas_1 = []
    i = 0
    while i < n:
        if mas[i] == mas[i+1]:
            new_mas_1.append(mas[i])
        i += 2
    LEN_MAS = len(new_mas_1)
    while LEN_MAS > 1:

        if LEN_MAS % 2:
            new_mas_1.append(new_mas_1[-2])

        new_mas_2 = []
        i = 0
        while i < LEN_MAS:
            if new_mas_1[i] == new_mas_1[i + 1]:
                new_mas_2.append(new_mas_1[i])
            i += 2
        LEN_MAS = len(new_mas_2)
        new_mas_1 = new_mas_2
    return LEN_MAS



def test(alg_correct, alg_to_test, name):
    global mas, n

    for n in tqdm(range(1, 100)):
        for _ in range(100):
            mas = [randint(0, 1) for _ in range(n)]

            timer = threading.Timer(1, timeout_handler)
            timer.start()
            ans1 = alg_to_test(mas, n)
            timer.cancel()
            ans2 = alg_correct(mas, n)
            if ans2 != ans1:
                print("ERROR!")
                print(f'n - {n}\nmas - {mas}\nright - {ans2}\nyour answer - {ans1}')
                print(*mas)
                exit(0)
    print(f"{name} - OK")


if __name__ == '__main__':
    mas, n = None, None
    test(find_dominant_element_with_hach, chech_dominant, 'O(n * log n)')
    test(find_dominant_element_with_hach, find_dominant_On, 'O(n)')
