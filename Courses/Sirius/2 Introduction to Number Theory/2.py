a, b, c = 36, -4, 5
expr = ((a - b)*c + b*c - (a + b*c*c)*(a + b + 1)) % 11
print(expr)
print('step by step')
print(f'1. a = {a % 11}; b = {b % 11}; c = {c % 11}')
print(f'2. (a - b)*c = {(a - b)%11} * {c} = {((a - b) * c)%11}')
print(f'3. b*c = {(b*c)%11}')
print(f'4. (a + b*c*c)*(a + b + 1) = {(a + b*c*c)%11} * {(a + b + 1)%11} = {((a + b*c*c)*(a + b + 1)) % 11}')
print(f'5. answer = {((a - b) * c)%11} + {(b*c)%11} - {((a + b*c*c)*(a + b + 1)) % 11} = {expr}')
