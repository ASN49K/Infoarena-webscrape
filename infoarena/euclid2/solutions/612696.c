#include <stdio.h>
#include <math.h>
int gcd(int a, int b){
if (!b) return a;
return gcd(b, a % b);
}
int main()
{
	FILE *fp = fopen("euclid2.in", "r");
	FILE *fo = fopen("euclid2.out", "w");
	int t = 0;
	int a = 0;
	int b = 0;
	
	fscanf(fp, "%d", &t);
	int i=0;
	for(i=0;i<t;i++){
		fscanf(fp, "%d", &a);
		fscanf(fp, "%d", &b);
		fprintf(fo, "%d\n",gcd(a,b));
	}	
	return 0;
	fclose(fp);	
	fclose(fo);	
}