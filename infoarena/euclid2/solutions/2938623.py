def euclid(a:int,b:int):
    if b<a:
        a,b=b,a
    while b!=0:
        r=a%b
        a=b
        b=r
    return a

if __name__ == '__main__':
    inputfile = open('euclid2.in','r')
    outputfile = open('euclid2.out','w')
    
    linii = int(inputfile.readline())
    for _ in range(linii):
        stringNumere = inputfile.readline()
        numere = []
        for numar in stringNumere.split(' '):
            numere.append(int(numar))
        outputfile.write(str(euclid(numere[0],numere[1])))
        outputfile.write('\n')
        
        