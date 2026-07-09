in_path = "euclid2.in"
out_path = "euclid2.out"
out_file = open(out_path, 'w')
lines = open(in_path).read()
print(lines)
lines = lines.split('\n')
print(lines)
n = int(lines[0])

def euclid(x,y):
    if(y == 0) :
        return x
    else:
        return euclid(y, x%y)

for i in range(1, n+1):
    curr = lines[i].split(' ')
    a = int(curr[0])
    b = int(curr[1])
    print(euclid(a, b), file = out_file)
