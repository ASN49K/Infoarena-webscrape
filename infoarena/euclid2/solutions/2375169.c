#include <stdio.h>

int cmmdc(int a, int b){	
	if(b == 0){
		return a;
	}else{
		return gcd(b, a%b);
	}	
}


int main(){

	FILE* f = fopen("euclid2.in", "r");
	FILE* out = fopen("euclid2.out", "w");
	int n, a, b;
	fscanf(f, "%d", &n);
	
	for (int i=0; i<n; ++i){
		fscanf(f, "%d %d", &a, &b);
		fprintf(out, "%d\n", cmmdc(a,b));
	}
	
	fclose(f);
	fclose(out);

	return 0;
}