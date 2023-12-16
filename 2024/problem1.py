import sys

n, m = sys.stdin.readline().split()
n = int(n)
m = int(m)
cow_heights = []
for height in sys.stdin.readline().split():
    cow_heights.append(int(height))

candy_heights = []
for height in sys.stdin.readline().split():
    candy_heights.append((0, int(height)))

for candy_height in candy_heights:
    new_cow_heights = []
    start, end = candy_height
    for cow_height in cow_heights:
        if cow_height >= start:
            eaten = min(cow_height, end) - start
            new_cow_heights.append(cow_height + eaten)
            start += eaten
        else:
            new_cow_heights.append(cow_height)
    cow_heights = new_cow_heights

for cow_height in cow_heights:
    print(cow_height)
