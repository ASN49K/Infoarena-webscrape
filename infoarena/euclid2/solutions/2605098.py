
def Cmmdc(a,b):
  if b==0: return a 
  else: return Cmmdc(b, a%b)

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