adds = tuple(str(sum(map(int, str(input()).split(' ')))) for _ in range(int(input())))

for idx, add in enumerate(adds):
    print("Case #{0}: {1}".format(idx+1, add))

