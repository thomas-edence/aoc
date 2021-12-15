def get_input_data():
    with open("input.txt") as ifile:
        return [int(line) for line in ifile.readlines()]


d = get_input_data()
d1, d2 = d[:-1], d[1:]
INCREASE, DECREASE = [1, 0]
items = [INCREASE if s - f > 0 else DECREASE for f, s in zip(d1, d2)]
result = sum(items)
print(result)

assert result == 1292
