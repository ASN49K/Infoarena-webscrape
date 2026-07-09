def euclid(num1: int, num2: int):
    # print(num1, num2)
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
    numbers = line.split(sep=' ')
    number1 = int(numbers[0])
    number2 = int(numbers[1])
    if number2 > number1:
        aux = number2
        number2 = number1
        number1 = aux
    euclid(number1, number2)
    # print(number1, number2, sep=' ')

g.close()
f.close()
