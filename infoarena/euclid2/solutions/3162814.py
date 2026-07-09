n = int(input())
for i in range(n-1):
    a, b = input().split()
    a, b = int(a), int(b)
    print(math.gcd(a,b))
