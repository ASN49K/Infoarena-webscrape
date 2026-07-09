import numpy as np


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

data = np.fromfile('euclid2.in', dtype=np.int32, sep=' ')

len = data[0]
print(data)
for i in range(len):
    if data[i * 2 + 1] > data[i * 2 + 2]:
        euclid(data[i * 2 + 1], data[i * 2 + 2])
    else:
        euclid(data[i * 2 + 1], data[i * 2 + 2])

g.close()
f.close()
