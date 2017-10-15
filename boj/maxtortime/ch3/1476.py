import time

E,S,M = map(int, str(input()).split(' '))
year = 1
e,s,m = 1,1,1

while not (e == E and m == M and s == S):
    e+=1
    s+=1
    m+=1
    year+=1

    if e == 16:
        e = 1

    if s == 29:
        s = 1

    if m == 20:
        m = 1

    # print(e,s,m)
    # time.sleep(1)

print(year)

