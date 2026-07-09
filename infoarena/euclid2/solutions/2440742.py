import numpy as np

def euclid_rec(a,b):
    if b == 0:
        return a
    return euclid_rec(b,a%b)

if __name__ == '__main__':
    file_input = open('euclid.in','r')
    file_output = open('euclid.out','w')
    entries = int(file_input.readline())
    for i in range(entries):
        line = file_input.readline().split(" ")
        a,b = int(line[0]),int(line[1])
        file_output.write(str(euclid_rec(a,b))+'\n')