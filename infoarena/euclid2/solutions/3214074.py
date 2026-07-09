
def euclid(a, b):
    if a < b:
        c = a
        a = b
        b = c
    while b:
        c = a % b
        a = b
        b = c
    return a


if __name__ == '__main__':
    fin = open('euclid2.in', 'r')
    fout = open('euclid2.out', 'w')
    list_lines = []
    s = int(fin.readline())
    while s > 0:
        tmp_string = fin.readline()
        list_nr = tmp_string.split()
        tmp_nrfout = str(euclid(int(list_nr[0]), int(list_nr[1]))) + '\n'
        list_lines += [tmp_nrfout]
        s -= 1
    fout.writelines(list_lines)
    fout.close()
    fin.close()
