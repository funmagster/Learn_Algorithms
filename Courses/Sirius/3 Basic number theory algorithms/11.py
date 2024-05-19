def get_div(n):
    i = 4
    while i*i <= n:
        if n % i == 0 and (n // i) % 2 == 0:
            return [i, n // i]
        i += 2
    return []


def even_prime(n):
    if n == 4:
        return 'single\n2 2'
    if (n // 2) % 2 == 1:
        return 'prime'
    div = get_div(n)
    if len(div):
        return f'many\n2 {n // 2}\n{div[0]} {div[1]}'
    return f'single\n2 {n // 2}'


# n = int(input())
# print(even_prime(n))

def solve(n):
    d = 0
    while not (n&1):
        d += 1
        n //= 2

    a = [2]*d
    a[-1] *= n
    if d == 1:
        return "prime"

    for x in range(3, int(n**.5)+1, 2):
        if not (n%x):
          b = a[:]
          b[-1] //= x
          b[-2] *= x
          s1 = " ".join(map(str, a))
          s2 = " ".join(map(str, b))
          return f'many\n{s1}\n{s2}'
    s = " ".join(map(str, a))
    return f"single\n{s}"


for n in range(2, 10_000, 2):
    res1 = even_prime(n)
    res2 = solve(n)
    if res1 != res2:
        print(f'n {n}\ncorrect:\n{res2}\nyou:\n{res1}')
        break