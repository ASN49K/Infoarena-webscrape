#include <stdio.h>

int cmmdc(int a, int b);
void change(int &a, int &b);

int main()
{
	FILE *inFile, *outFile;
	int a, b, c;
	
	inFile = fopen("euclid2.in", "r");
	outFile = fopen("euclid2.out", "w");

	fscanf(inFile, "%d %d", &a, &b);

	c = cmmdc(a, b);

	fprintf(outFile, "%d", c);

	fclose(inFile);
	fclose(outFile);
}

int cmmdc(int a, int b)
{
	if(a < b)
		change(a, b);
	while (a > b && b != 0 && b != 1)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	if(b == 1)
		return 0;
	return a;
}

void change(int &a, int &b)
{
	int aux = a;
	a = b;
	b = aux;
}