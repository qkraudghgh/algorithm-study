from itertools import combinations as comb

combs = []

while True:
    nums = tuple(map(int, input().split()))
    n = int(nums[0])

    if n == 0:
        break
    else:
        combs.append(comb(nums[1:], 6))

for elem in combs:
    for n in elem:
        print(' ' .join(map(str, n)))

    print('')

