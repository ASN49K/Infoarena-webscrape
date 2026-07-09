#include<stdio.h>
#define NMAX 1025

class Stack{
	public:
		short *stackArray;
		short dim;

		Stack(){
			dim = 0;
			stackArray = new short[NMAX];
		}

		~Stack(){
			delete[] stackArray;
			dim = 0;
		}

		void push(short x){
			dim++;
			stackArray[dim] = x;
		}

		short pop(){
			if(isEmpty()){
				short x;
				fprintf(stderr, "Stack is empty!\n");
				return x;
			}
			short x = stackArray[dim];
			dim--;
			return x;
		}

		int isEmpty(){
			if(dim == 0)
				return 1;
			return 0;
		}
};

short max(short a, short b){
	if(a > b)
		return a;
	else
		return b;
}

int main(){
	Stack S;
	short M, N, i, j;
	short A[NMAX], B[NMAX], D[NMAX][NMAX];
	FILE *pf, *pg;

	pf = fopen("cmlsc.in", "r");
	pg = fopen("cmlsc.out", "w");

	fscanf(pf, "%hd %hd", &M, &N);
	D[0][0] = 0;

	for(i=1; i<=M; i++){
		fscanf(pf, "%hd", &A[i]);
		D[i][0] = 0;
	}

	for(i=1; i<=N; i++){
		fscanf(pf, "%hd", &B[i]);
		D[0][i] = 0;
	}


	for(i=1; i<=M; i++)
		for(j=1; j<=N; j++)
			if(A[i] == B[j])
				D[i][j] = D[i-1][j-1] + 1;
			else
				D[i][j] = max(D[i-1][j], D[i][j-1]);

	fprintf(pg, "%hd\n", D[M][N]);

	i = M;
	j = N;
	while(i > 0 && j > 0)
		if(A[i] == B[j]){
			S.push(A[i]);
			i--;
			j--;
		}
		else
			if(D[i][j-1] > D[i-1][j])
				j--;
			else
				i--;

	while(!S.isEmpty())
		fprintf(pg, "%hd ", S.pop());

	fclose(pf);
	fclose(pg);

	return 0;

}
			 

	
			
