import re
l=[]
p="\n"
n=int(input())
with open("euclid2.in","w")as w:
    w.write(str(n))
    w.write(p)
    i=0
    while i<n:
        m=str(input())
        w.write(m)
        w.write(p)
        i+=1
with open("euclid2.in","r") as r:
    date=r.read()
    pattern=re.compile("\d+")
    rez=pattern.findall(date)
    x=rez[0:len(rez)-len(rez)+1]
    i=int(x[0])
    A = 1
    B = 3
with open("euclid2.out","w")as w:
    for x in range(1,i+1):
        l=rez[A:B]
        A=A+2
        B=B+2
        a=int(l[0])
        b=int(l[1])
        while a!=0:
            r=b%a
            b=a
            a=r
        w.write(str(b))
        w.write(p)














