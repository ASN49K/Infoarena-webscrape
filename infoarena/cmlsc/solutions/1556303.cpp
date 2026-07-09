#include <iostream>
#include <stdio.h>
#include <algorithm> 
using namespace std;


int M, N;
int a[1024];
int b[1024];
int c[1024];
int cSize;

int C[1024 * 1024];

void printArray(const int * a , int len){
	for(int i = 0 ; i < len ; ++i){
		cout << a[i] << " " ;
	}
	cout << endl;
}


void printMatrix(const int * matrix , const int & width , const int & height){
	int i = 0;
	int j = 0;
	
	for(i = 0 ; i < height ; i++){
		for(j = 0 ; j < width ; j++){
			cout << matrix[i * width + j] << " ";
		}
		cout << endl;
	}
}

void cmlsc(int * C , const int &width , const int &height , const int * X , const int * Y , int * out, int &cSize){
	
	int i = 0;
	int j = 0;
	
	//full 0 on the first row
	for(int i = 0 ; i < width ; i++)
		C[0 * width + i] = 0;
		
	//full 0 on the first column
	for(int i = 0 ; i < M ; i++){
		C[i * width + 0] = 0;
	}
	
	
	for(i = 0 ; i < height ; i++){
		for(j = 0 ; j < width ; j++){
			if(X[i] == Y[j]){
				C[i * width + j] = C[(i-1) * width + (j-1)] + 1;
				*out = X[i];
				out++;
				cSize++;
			}else{
				C[i * width + j] = max (C[(i-1) * width + j] , C[i * width + (j-1)]);
			}
		}
	}
}


int main(){
	
	FILE * inFile = fopen("in/cmlsc.in" , "r");
	FILE * outFile = fopen("out/cmlsc.out" , "w+");
	
	fscanf(inFile , "%d %d\n", &M , &N);
	for(int i = 0; i < M ; ++i){
		fscanf(inFile , "%d" , a + i);
	}
	
	for(int i = 0 ; i < N ; ++i){
		fscanf(inFile , "%d" , b + i);
	}
	
	
	// printArray(a, M);
	// printArray(b, N);
	
	cmlsc(C , N, M, a, b , c , cSize);
	
	// printMatrix(C , N , M);
	// printArray(c, cSize);
	
	fprintf(outFile, "%d\n", C[(M-1) * N + (N-1)]);
	for(int i = 0 ; i < cSize ; i++){
		fprintf(outFile , "%d " , c[i]);
	}
	
	fflush(outFile);
	fclose(inFile);
	fclose(outFile);
	
	return 0;
}