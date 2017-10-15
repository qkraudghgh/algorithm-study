import math
N = int(input())
f = [1 for i in range(21)]

for idx in range(1, 21):
    f[idx] = f[idx-1] * idx

c = [False for _ in range(21)]

second_line = str(input()).split(' ')
pr_type = int(second_line[0])

if pr_type == 1:
    k = int(second_line[1])
    P = [0 for _ in range(N)]

    for i in range(N):
        for j in range(1, N+1):
            if c[j]:
                continue

            if f[N-i-1] < k:
                k -= f[N-i-1]
            else:
                P[i] = j
                c[j] = True
                break

    print(' '.join(map(str, P)))
elif pr_type == 2:
    P = list(map(int,second_line[1:]))
    ans = 0

    for i in range(N):
        for j in range(1, P[i]):
            if not c[j]:
                ans += f[N-i-1]

        c[P[i]] = True

    print(ans+1)

