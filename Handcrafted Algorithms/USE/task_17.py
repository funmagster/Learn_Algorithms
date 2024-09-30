f = open('69927.txt')
a = [int(x) for x in f]
count_delit_32 = 0

for i in range(len(a)):
    if a[i] % 32 == 0:
        count_delit_32 += 1
answer = []

for j in range(len(a)-1):
    if (a[j] < 0 or a[j+1] < 0) and ((a[j] + a[j+1]) < count_delit_32):
        answer.append(a[j] + a[j+1])
print(len(answer), max(answer))