def find_reciprocal_number(a, p):
    return pow(a, p-2, p)


t = int(input())
for _ in range(t):
    p, a = map(int, input().split())
    print(find_reciprocal_number(a, p))
