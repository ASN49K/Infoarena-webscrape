#include <stdio.h>

int main() {

	FILE *fin, *fout;
    fout = fopen("euclid2.out","w+");
	fin = fopen("euclid2.in", "r+");
	long t, a, b;
	fscanf (fin, "%li", &t);
	
	for ( ;t > 0; t--) {
		
		fscanf (fin, "%li", &a);
		fscanf (fin, "%li", &b);
		long aux;
		if ( a < b){
			aux = a;
			a = b;
			b = aux;
		}
		while ( b != 0 ) {
			a = a % b;
			aux = b;
			b = a;
			a = aux;
		}
		fprintf(fout, "%li\n", a);
	}
	fclose(fout);
	fclose(fin);


}
