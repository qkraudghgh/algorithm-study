M = int(input())
S = [False for _ in range(20)]
R = []

for i in range(M):
    cmd, x = str(input()).split(' ')
    x = int(x)

    if cmd == "add":
        S[x] = True
    elif cmd == 'check':
        print(1 if S[x] else 0)
    elif cmd == 'toggle':
        S[x] = False if S[x] else True
    elif cmd == 'all':
        S = [True for _ in range(20)]
    elif cmd == 'empty':
        S = [False for _ in range(20)]

