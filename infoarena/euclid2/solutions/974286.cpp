#include<stdio.h>

int cmmdc(int a, int b){
	if(b == 0)
		return a;
	else
		return cmmdc(b, a%b);
}

int main(){
	int a, b, T, i, d;
	FILE *pf, *pg;

	pf = fopen("euclid2.in", "r");
	pg = fopen("euclid2.out", "w");

	fscanf(pf, "%d", &T);

	for(i = 1; i <= T; i++){
		fscanf(pf, "%d %d", &a, &b);
		
		if(a > b)
			d = cmmdc(a, b);
		else
			d = cmmdc(b, a);

		fprintf(pg, "%d\n", d);
	}

	return 0;
}
