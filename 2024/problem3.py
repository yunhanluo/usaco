import sys
t = int(sys.stdin.readline())

results = []
for i in range(t):
    n = int(sys.stdin.readline())
    heights = [int(h) for h in sys.stdin.readline().split()]
    growths = [int(h) for h in sys.stdin.readline().split()]
    diffs = [int(h) for h in sys.stdin.readline().split()]
    diffs = {i: d for i, d in enumerate(diffs)}
    diffs = sorted(diffs, key=lambda key: diffs[key])

    if n <= 1:
        results.append(0)
        continue

    days = 0
    while True:
        satisfied = True
        if days > 1000:
            results.append(-1)
            break

        for j in range(n - 1):
            if heights[diffs[j]] <= heights[diffs[j+1]]:
                satisfied = False

        if satisfied:
            results.append(days)
            break

        impossible = False
        for j in range(n - 1):
            if heights[diffs[j]] <= heights[diffs[j+1]] and growths[diffs[j]] <= growths[diffs[j+1]]:
                impossible = True
                break
        if impossible:
            results.append(-1)
            break
        # if len(set(growths)) != len(growths):
        #    results.append(-1)
        #    break

        for j in range(n):
            heights[j] += growths[j]
        days += 1

for result in results:
    print(result)

