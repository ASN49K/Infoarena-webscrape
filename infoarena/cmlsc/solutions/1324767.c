#include <stdio.h>
#define Nmax 1024


int main(int argc, char* argv[]) {

	FILE *in;
	FILE *out;

	in = fopen("cmlsc.in", "r");
	out = fopen("cmlsc.out", "w");

	if( in == NULL) {
	
		fprintf(stderr, "Can't open file!\n");
		return 0;
	}

	int M, N;

	if(	fscanf(in, "%d %d", &M, &N) )  {

	int i = 0;
	int A[Nmax];
	int B[Nmax];

	for ( i = 0; i < M; i++) {
		
		fscanf(in, "%d", &A[i]);
	}

	for ( i = 0 ; i < N; i++) {

		fscanf(in, "%d", &B[i]);
	}

	int C[Nmax];
	int j = 0;
	int MAX = 0;

	for( i = 0 ; i < M; i++ ) {
		for( j = 0 ; j < N; j++) {
			
				if( A[i] == B[j] ) {

					C[MAX] = A[i];
					MAX++;
				}
		}
	}

	fprintf(out, "%d\n", MAX);

	for( i = 0; i < MAX; i++) {

		fprintf(out, "%d ", C[i]);
	}
	}
	fclose(in);
	fclose(out);

	return 0;
}

