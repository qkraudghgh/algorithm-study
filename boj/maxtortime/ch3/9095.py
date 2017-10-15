d = [0 for _ in range(1, 11)]
d[0] = 1
d[1] = 2
d[2] = 4

T = int(input())

for _ in range(T):
    n = int(input())
    r = d[n-1]

    if r == 0:
        for i in range(3, n):
            d[i] = d[i-1] + d[i-2] + d[i-3]

        r = d[n-1]

    print(r)

