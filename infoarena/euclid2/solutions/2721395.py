def Euclid(a,b):
	while not b == 0:
		  r = a % b;
		  a = b
		  b = r
	return a
		  
def main():
    allNums = []
    out = open('euclid2.out','w')
    with open("euclid2.in") as f:
        data = f.readlines()
    	for line in data:
    	    allNums += line.strip().split(" ")
    n = int(allNums[0])	
    
    i = 1
    while not i == (n * 2 + 1):    	
          a , b = int(allNums[i]), int(allNums[i+1])                   
          gcd = Euclid(a,b)          
          out.write(str(gcd) + "\n")
          i += 2

main()
