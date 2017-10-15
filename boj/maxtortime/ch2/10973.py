"""
* A[i-1] < A[i]를 만족하는 가장 큰 i
 * j >= i 이면서 A[j] > A[i-1]를 만족하는 가장 큰 i
 * A[i-1]와 A[j]를 스왑
 * A[i] 부터 순열 뒤집기
 *
 * 1 2 3 4
 * j = i = 3
 * 1 2 4 3
 *

 *
 */
"""

def before_permutation(p):
    if p == list(sorted(p)):
        return -1

    I = 1
    J = I

    for i in range(I, len(p)):
        if p[i-1] > p[i]:
            I = i

    for j in range(I, len(p)):
        if p[j] < p[I-1]:
            J = j

    temp = p[I-1]
    p[I-1] = p[J]
    p[J] = temp

    return ' '.join(tuple(map(str, p[:I] + list(reversed(p[I:])))))



N = int(input())
P = list(map(int, str(input()).split(' ')))

print(before_permutation(P))




