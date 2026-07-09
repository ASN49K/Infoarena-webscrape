def euclid(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a

def main():
    try:
        with open("euclid2.in", "r") as f:
            lines = f.readlines() 

        results = []
        
        for line in lines[1:]: 
            parts = line.strip().split()
            
            if len(parts) >= 2:
                x = int(parts[0])
                y = int(parts[1])
                results.append(str(euclid(x, y)))

        with open("euclid2.out", "w") as g:
            g.write("\n".join(results))

    except:
        pass

if __name__ == "__main__":
    main()