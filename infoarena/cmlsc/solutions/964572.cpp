#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int numbers_A, numbers_B;
int main(){

	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	int i, j;
	fin>>numbers_A>>numbers_B;
	int A[numbers_A], B[numbers_B];
	int mat[numbers_A+1][numbers_B+1];
	int common[1000], k = 0;
	// citire numere
	for(i = 0; i < numbers_A; i++){
		fin>>A[i];
 	}
 	for(i = 0; i < numbers_A+1; i++){
		mat[i][0] = 0;
	}
 	for (i = 0; i < numbers_B; i++){
		fin>>B[i];
	}
	for(i = 0; i < numbers_B+1; i++){
		mat[0][i] = 0;
	}
	for(i = 1; i < numbers_A+1; i++){
		for(j = 1; j < numbers_B+1; j++){
			if (A[i-1] == B[j-1]){
				mat[i][j] = mat[i-1][j-1] + 1;
				common[k++] = A[i-1];
			}else{
				mat[i][j] = fmax(mat[i-1][j],mat[i][j-1]);
			}
		}
	}
	fout<<mat[numbers_A+1][numbers_B+1]<<"\n";
	for (i = 0; i < k; i++){
		fout<<common[i]<<" ";
	}
	fout<<"\n";
	return 0;
	
}
