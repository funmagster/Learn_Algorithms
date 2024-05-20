def is_break(n, c, p):
    ans = ['no']*n
    for press in p:
        c[press - 1] -= 1
        if c[press - 1] < 0:
            ans[press - 1] = 'yes'
    return ans


n = int(input())    
c = list(map(int, input().split()))
k = int(input())
p = list(map(int, input().split()))
print(*is_break(n, c, p), sep='\n')
