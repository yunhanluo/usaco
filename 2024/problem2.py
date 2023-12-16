def count_cows(cows):
    start = -1
    end = -1
    infected = []
    for i, cow in enumerate(cows):
        if cow == '1':
            if start == -1:
                start = i
                end = i
            else:
                end = i
        else:
            if start != -1:
                infected.append((start, end))
                start = -1
                end = -1

    if start != -1:
        infected.append((start, end))

    head = []
    tail = []
    if infected[0][0] == 0:
        head = [infected[0]]
        infected = infected[1:]

    if infected and infected[-1][1] == len(cows) - 1:
        tail = [infected[-1]]
        infected = infected[:-1]

    middle = infected

    while True:
        new_head = []
        new_middle = []
        new_tail = []
        if head:
            changed = False
            new_head = []
            for start, end in head:
                if end - start == 1:
                    new_head.append((start, end -1))
                    changed = True
                elif end - start > 1:
                    new_head.append((start, end -1))
                    new_head.append((start + 1, end - 1))
                    changed = True

            if not changed:
                break

        if tail:
            changed = False
            new_tail = []
            for start, end in tail:
                if end - start == 1:
                    new_tail.append((start + 1, end))
                    changed = True
                elif end - start > 1:
                    new_tail.append((start + 1, end))
                    new_tail.append((start + 1, end - 1))
                    changed = True

            if not changed:
                break

        if middle:
            unchanged = False
            new_middle = []
            for start, end in middle:
                if end - start >= 2:
                    new_middle.append((start +1, end - 1))
                else:
                    unchanged = True

            if unchanged:
                break

        head = new_head
        middle = new_middle
        tail = new_tail

    head_count = 0
    if head:
        head_count = len(cows)
        for start, end in head:
            head_count = min(head_count, end - start + 1)

    tail_count = 0
    if tail:
        tail_count = len(cows)
        for start, end in tail:
            tail_count = min(tail_count, end - start + 1)

    middle_count = 0
    for start, end in middle:
        middle_count += end - start + 1

    return head_count + middle_count + tail_count


print(count_cows(list('011101')))
