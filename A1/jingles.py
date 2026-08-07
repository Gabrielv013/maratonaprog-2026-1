m = {
    'W': 1,
    'H': 1/2,
    'Q': 1/4,
    'E': 1/8,
    'S': 1/16,
    'T': 1/32,
    'X': 1/64
}

while True:
    j = input()
    if j == '*':
        break

    measures = j.split('/')
    correct = 0

    for measure in measures:
        total = 0
        for c in measure:
            total += m[c]
        if total == 1:
            correct += 1

    print(correct)
