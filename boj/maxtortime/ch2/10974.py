import math

def permutation(p):
    I = 1
    J = I

    for i in range(I, len(p)):
        if p[i-1] < p[i]:
            I = i

    for j in range(I, len(p)):
        if p[j] > p[I-1]:
            J = j

    temp = p[I-1]
    p[I-1] = p[J]
    p[J] = temp

    return list(map(str, p[:I] + list(reversed(p[I:]))))



N = int(input())

p = [str(n) for n in range(1, N+1)]

print(' '.join(p))

for _ in range(math.factorial(N)-1):
    p = permutation(p)
    print(' '.join(p))

