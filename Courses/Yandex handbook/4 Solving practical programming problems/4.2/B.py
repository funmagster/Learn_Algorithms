n = int(input())
pol1 = list(map(int, input().split()))
m = int(input())
pol2 = list(map(int, input().split()))
if n < m:
    n, m = m, n
    pol1, pol2 = pol2, pol1
print(n)
for i in range(n-m):
    print(pol1[i], end=' ')
for i in range(m+1):
    print(pol1[n-m + i] + pol2[i], end=' ')