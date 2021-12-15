def get_input_data():
    with open("input.txt") as ifile:
        return [int(line) for line in ifile.readlines()]


d = get_input_data()
WINDOW = 3
dp = [
    sum([v, sum([d[i+j] for j in range(1, WINDOW)])])
    for i, v in enumerate(d[: 1 - WINDOW])
]
d1, d2 = dp[:-1], dp[1:]
INCREASE, DECREASE = [1, 0]
items = [INCREASE if s - f > 0 else DECREASE for f, s in zip(d1, d2)]
result = sum(items)
print(result)

assert result == 1262
