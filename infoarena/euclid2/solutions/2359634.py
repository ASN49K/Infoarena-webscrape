def gcd(l: int, r: int) -> int:
    return l if r == 0 else gcd(r, l % r)


if __name__ == '__main__':
    file = open('euclid2.in', 'r')
    numbers = [(int(l), int(r)) for l, r in
               [x.replace('\n', '').split(' ')
                for x in file.readlines()[1:]]]
    file.close()
    results = [str(gcd(l, r)) + '\n' for l, r in numbers]
    output = open('euclid2.out', 'w')
    output.writelines(results)
    output.close()
