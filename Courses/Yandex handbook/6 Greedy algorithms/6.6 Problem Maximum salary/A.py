def isbetter(new_num, old_num):
    if old_num:
        a, b = new_num + old_num, old_num + new_num
        if a == b:
            return len(a) > len(b)
        return a > b
    return True


def get_salary(n, numbers):
    salary = []
    numbers_use = [False]*n
    for _ in range(n):
        max_num = ''
        ind_max_num = -1
        for ind, num in enumerate(numbers):
            if not numbers_use[ind]:
                if isbetter(num, max_num):
                    ind_max_num = ind
                    max_num = num
        salary.append(max_num)
        numbers_use[ind_max_num] = True
    return ''.join(salary)


n = int(input())
numbers = input().split()
print(get_salary(n, numbers))
