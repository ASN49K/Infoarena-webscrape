#include <stdio.h>

int Euclid(int a, int b){
	int aux;
	if(!b)
		return a;
	else 
		aux = Euclid(b, a%b);
	return aux;
}

int main(){
	FILE *in;
	in = fopen("euclid2.in", "r");
	FILE *out;
	out = fopen("euclid2.out", "w");

	int T = 0, a, b, cmmdc;
	fscanf(in, "%d", &T);
	
	while(T != 0){
		cmmdc = 0;
		fscanf(in, "%d %d", &a, &b);
		if(a > b)
			cmmdc = Euclid(a, b);
		else
			cmmdc = Euclid(b, a);
		T--;
		fprintf(out, "%d\n", cmmdc);
	}

	

	fclose(in);
	fclose(out);
	return 0;
}