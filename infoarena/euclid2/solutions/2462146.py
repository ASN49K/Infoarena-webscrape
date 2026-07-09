f = open("euclid2.in","r")
g = open("euclid2.out","w+")

a = f.read()
print(a.split());

[a, b] = a.split()

a = int(a);
b = int(b);

while (b != a):
    if (b > a):
        b -= a;
    else:
        a -= b;

g.write(str(a));
