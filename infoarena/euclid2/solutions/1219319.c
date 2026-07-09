#include <stdio.h>

#define FIN "euclid2.in"
#define FOUT "euclid2.out"

int euclid(int a, int b){
	if(a%b) return euclid(b, a%b);
	return b;
}

int main(){
	int N,a,b;
	FILE *in, *out;
	in = fopen(FIN, "rt");
	out = fopen(FOUT, "wt");
	fscanf(in, "%d", &N);
	for(; N; N--){
		fscanf(in, "%d%d", &a, &b);
		
		fprintf(out, "%d\n", euclid(a,b));
	}
	return 0;
}
