#include<stdio.h>
#include<fstream>
using namespace std;
unsigned gcd(unsigned a, unsigned b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main()
{
	/*FILE *in, *out;
	in = fopen("euclid2.in", "r");
	out = fopen("euclid2.out", "w");
	unsigned T, a, b,i;
	fscanf(in, "%u", &T);
	for (i = 1; i <= T; i++)
	{
		fscanf(in, "%u %u", &a, &b);
		fprintf(out, "%u\n", gcd(a, b));
	}*/
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	unsigned T, a, b, i;
	f >> T;
	for (i = 1; i <= T; i++)
	{
		f >> a >> b;
		g << gcd(a, b) << " \n";
	}
}