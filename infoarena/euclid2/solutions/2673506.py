
with open('euclid2.in', 'r') as reader, open('euclid2.out', 'w') as writer:
    T = int(reader.readline())

    while T>0:
       values = reader.readline()
       a, b = [int(value) for value in values.split()]
       
       minim = min(a, b)
       for idx in range(minim,0,-1):
           if (a % idx == 0 and b % idx == 0):
               writer.write(str(idx), '\n')
               break
       
       T -= 1