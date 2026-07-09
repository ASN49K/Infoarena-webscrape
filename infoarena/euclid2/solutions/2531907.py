from typing import Union

input_file = open("euclid2.in", "r")
output_file = open("euclid2.out", "w")

i = 0


def cmmdc(a, b):
	r = a % b
	while r != 0:
		r = a % b
		a = b
		b = r
	return a


def Get_Number(line):
	c: str = ""
	global  i
	while i < n:
		if line[i] >= '0' and line[i] <= '9':
			while i < n and line[i] >= '0' and line[i] <= '9':
				c += line[i]
				i += 1
			return c
		i += 1
	return 0


n = input_file.readline()

for j in range(int(n)):
	i = 0
	line = input_file.readline()
	#print(line)
	n = len(line)
	a = Get_Number(line)
	b = Get_Number(line)
	if int(a) > int(b):
		aux = a
		a = b
		b = aux
#	print("Numerele sunt %s si %s" %(a,b))
	c = cmmdc(int(a),int(b))
	output_file.write(str(c))
	output_file.write("\n")
# output_file.write(c)
# output_file.write("\n")

input_file.close()
output_file.close()
