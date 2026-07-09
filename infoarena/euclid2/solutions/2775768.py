def euclid(num1: int, num2: int):
    numerator = num1
    denominator = num2
    while denominator != 0:
        temp_numerator = numerator
        numerator = denominator
        denominator = temp_numerator % denominator

    g.write(str(numerator) + '\n')


f = open('euclid2.in', 'r')
g = open('euclid2.out', 'w')

lines = f.readline()
for line in f:
    split = line.split(sep=' ')
    numbers = [int(s) for s in split]
    if numbers[1] > numbers[0]:
        euclid(numbers[1], numbers[0])
    else:
        euclid(numbers[0], numbers[1])

g.close()
f.close()
