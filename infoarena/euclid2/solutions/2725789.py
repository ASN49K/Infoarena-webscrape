def Euclid(a,b):
    while b:
      r = a % b
      a = b
      b = r
    return a  	 

def main():
	out = open('euclid2.out','w')
	with open('euclid2.in','r') as file:
		lines = []
		for line in file:
			lines.append(line.strip())
		T = int(lines[0])
		for i in range(1, T + 1):
			a = int(lines[i].split(" ")[0])
			b = int(lines[i].split(" ")[1])            
			out.write(str(Euclid(a,b)) + '\n')

            
main()