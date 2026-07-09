
def Cmmdc(a,b):
  while b!=0:
    r=a%b
    a=b
    b=r
  return a

def read_file(f_Input, f_Output):
  f = open(f_Input,"r")
  u = open(f_Output,"w")
  T = int(f.readline().strip())
  for i in range(T):
    linie = f.readline().strip().split(" ")
    divCom = Cmmdc(int(linie[0]),int(linie[1]))
    print(divCom, end="\n", file=u)
  f.close()
  u.close()

def Main():
  read_file("euclid2.in","euclid2.out")

Main()