from functools import reduce
in_file,out_file=open("nim.in","r"),open("nim.out","w")
t=(int)(in_file.readline())
output=""
for Test in range(t):
    useless=in_file.readline()
    output+="NU\n" if reduce(lambda x,y:x^y,map(int,in_file.readline().split()))==0 else "DA\n"
out_file.write(output)
