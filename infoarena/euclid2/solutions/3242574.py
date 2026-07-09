import string
from dataclasses import dataclass

from bitarray import bitarray


@dataclass(frozen=True)
class Constants:
    INPUT: string = "/Users/lucadani/PycharmProjects/InfoArenaPython/Ciurul_lui_Eratostenes/ciur.in"
    OUTPUT: string = "/Users/lucadani/PycharmProjects/InfoArenaPython/Ciurul_lui_Eratostenes/ciur.out"


def count_primes_until_fixed_value(value):
    sieve = bitarray(value + 1)
    sieve.setall(True)
    sieve[0], sieve[1] = False, False
    for i in range(2, int(value ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, value + 1, i):
                sieve[j] = False
    cnt = 0
    for elem in sieve:
        if elem:
            cnt += 1
    return cnt


if __name__ == "__main__":
    with open(Constants.INPUT, "r") as file:
        n = int(file.readline().strip())

    with open(Constants.OUTPUT, "w") as file:
        file.write(str(count_primes_until_fixed_value(n)))
