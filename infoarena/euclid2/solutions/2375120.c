#include <stdio.h>

int cmmdc(int a, int b){	
	if(a == b){
		return a;
	}else{
		if(a > b){
			return cmmdc(a-b, b);
		}
		else{
			return cmmdc(a, b-a);
		}
	}	
}


int main(){

	FILE* f = fopen("euclid2.in", "r");
	FILE* out = fopen("euclid2.out", "w");
	int n, a, b;
	fscanf(f, "%d", &n);
	for (int i=0; i<n; ++i){
		fscanf(f, "%d", &a);
		fscanf(f, "%d", &n);
		fprintf(f, "%d\n", cmmdc(a,b));
	}
	
	fclose(f);
	fclose(out);

	return 0;
}