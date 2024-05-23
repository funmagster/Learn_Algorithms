def solve_number(num):
    power_of_two = 0
    while num % 2 == 0:
        power_of_two += 1
        num //= 2

    sequence = [2] * power_of_two
    sequence[-1] *= num

    if power_of_two == 1:
        return "prime", None

    factor = 3
    while factor * factor <= num:
        if num % factor == 0:
            alternative_sequence = sequence.copy()
            alternative_sequence[-1] //= factor
            alternative_sequence[-2] *= factor
            return "many", [sequence, alternative_sequence]
        factor += 2

    return "single", [sequence]


number = int(input())
even, factor = solve_number(number)
print(even)
if not factor is None:
    for div in factor:
        print(*div, sep=' ')
