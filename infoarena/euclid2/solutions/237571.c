#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b) {
	if (!b) 
		return a;  
	return cmmdc(b, a % b);  
}

int main() {
	FILE *f, *g;
	int T,a,b;
	f=fopen("euclid2.in", "r");
	g=fopen("euclid2.out", "w");
	fscanf(f, "%d", &T);
	while(T--) {
		fscanf(f, "%d %d", &a,&b);
		fprintf(g, "%d\n", cmmdc(a,b));
	}
	fclose(f);
	fclose(g);
	return 0;
}
