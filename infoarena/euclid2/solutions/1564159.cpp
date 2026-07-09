#include <cstdio>

using namespace std;

FILE * iFile;
FILE * oFile;

int gcd(int a, int b) {
	int r;

	while(b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
	
int main()
{
	iFile = fopen("euclid2.in", "r");
	oFile = fopen("euclid2.out", "w");

	int n, a, b;

	fscanf(iFile, "%d", &n);

	for(int i=1; i <= n; i++) 
	{
		fscanf(iFile, "%d %d", &a, &b);

		fprintf(oFile, "%d\n", gcd(a,b));
	}

	return 0;
}