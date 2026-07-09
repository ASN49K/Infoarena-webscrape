#include <stdio.h>
using namespace std;

int cmmdc(int a, int b)
{
	if (b == 0)
		return a;
	else return cmmdc(b, a % b);
}
int main()
{
	FILE *in = fopen("euclid2.in", "r"),
		*out = fopen("euclid2.out", "w");
	int a, b, n;
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; i++){
		fscanf(in, "%d %d", &a, &b);
		fprintf(out, "%d\n", cmmdc(a, b));
	}
	return 0;
}
