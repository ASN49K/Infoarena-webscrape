#include <stdio.h>

int main() {
	FILE *fin = fopen("euclid2.in","r");
	FILE *fout = fopen("euclid2.out","w");
	
	long n;
	long a,b,c;
	fscanf(fin,"%ld\n",&n);
	for (int i=1; i<=n; i++) {	
		fscanf(fin,"%ld %ld",&a,&b);
		
		while (a % b != 0) {
			c = a%b;
			a = b;
			b = c;
		}
		
		fprintf(fout,"%ld\n",b);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
