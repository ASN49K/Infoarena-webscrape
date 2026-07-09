#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(int argc, char *argv[])
{
 	// freopen("euclid2.in", "r", stdin);
	ifstream f{"euclid2.in"};
 	// freopen("euclid2.out", "w", stdout);
      	ofstream g{"euclid2.out"};

	int n, a, b;
	// scanf("%d", &n);
	f >> n;
	for (int i = 0; i < n; i++) {
		// scanf("%d %d", &a, &b);
		f >> a >> b;
		g << gcd(a, b) << "\n"; 
		// printf("%d\n", gcd(a, b));
	}
	return 0;
}
