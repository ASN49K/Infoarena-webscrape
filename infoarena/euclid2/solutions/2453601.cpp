 #include <cstdio>
 
 using namespace std;
 
 int gcd(int a, int b) {
	if (b > a) {
		return gcd(b, a);
	}
	
	int r = a % b;
	
	if (r == 0) {
		return b;
	}
	
	return gcd(b, r);
 }
 
 int main ()
 {
	 freopen("euclid2.in", "r", stdin);
	 freopen("euclid2.out", "w", stdout);
	 
	 int T, a, b;
	 
	 scanf ("%d", &T);
	 
	 for (int i = 0; i < T; i++) {
		 scanf("%d%d", &a, &b);
		 
		 if (a == b) {
			printf("%d\n", a);
			continue;
		 }
		 
		 printf("%d\n", gcd(a, b));
	 }
	 
	 return 0;
 }