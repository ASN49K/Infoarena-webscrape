# https://www.infoarena.ro/problema/euclid2
#
# Input:
#	euclid2.in
# Output:
#	euclid2.out

def euclid_it(a: int, b: int):
	divizor = 1
	for i in range(2, min(a, b) + 1):
		if (a % i == 0) and (b % i == 0):
			divizor = i
	return divizor

def euclid_sub(a: int, b: int):
	pass

def euclid_div(a: int, b: int):
	pass


with open('euclid2.in', 'r') as inFile:
	count = int(inFile.readline())
	with open('euclid.out', 'w') as outFile:
		while count > 0:
			line = inFile.readline()
			[a, b] = map(lambda entry: int(entry), line.split(' '))
			result = euclid_it(a, b)
			outFile.write(repr(result) + "\n")
			count -= 1
