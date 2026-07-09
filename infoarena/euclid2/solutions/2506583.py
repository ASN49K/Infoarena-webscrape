IN_FILE = "euclid2.in"
OUT_FILE = "euclid2.out"

def gcd(a,b):
    while (b!=0) :
        rest = a%b
        a = b
        b = rest
    return a
    

def main():
    with open(IN_FILE, "r") as f:
        lines = int(f.readline())
        for index in range(0, lines):
            line = f.readline().split(" ")
            a, b = int(line[0]), int(line[1])
            with open(OUT_FILE, "a") as o:
                o.write(str(gcd(a,b)))
                o.write("\n")

main()
