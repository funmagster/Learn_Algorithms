from tqdm import tqdm

def C_x(x):
    A = [i * i for i in range(1, x+4)]
    B = [i * i * i for i in range(1, x+4)]
    a_i = 0
    b_i = 0
    c_x = A[0]
    i = 0
    while i < x:
        if A[a_i] == B[b_i]:
            a_i += 1
        if A[a_i] < B[b_i]:
            c_x = A[a_i]
            a_i += 1
        else:
            c_x = B[b_i]
            b_i += 1
        i += 1
    return c_x


x = int(input())
print(C_x(x))
