#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int numbers_A, numbers_B;
int A[1025], B[1025];
int mat[1025][1025],mirr[1025][1025];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
void afiseaza(int i, int j){
	
	if(mirr[i][j] == 0){
		return;
	}else{
		if(mirr[i][j] == 1){
			i = i-1;
			j = j-1;
			afiseaza(i,j);
			fout<<A[i]<<" ";
		}else{
			if(mirr[i][j] == 2){
				i = i-1;
				afiseaza(i, j);
			}else{
				j = j - 1;
				afiseaza(i, j);
			}
		}
	}
}
int main(){

	
	int i, j;
	fin>>numbers_A>>numbers_B;
	// citire numere
	for(i = 0; i < numbers_A; i++){
		fin>>A[i];
 	}
 	for(i = 0; i < numbers_A+1; i++){
		mat[i][0] = 0;
		mirr[i][0] = 0;
	}
 	for (i = 0; i < numbers_B; i++){
		fin>>B[i];
	}
	for(i = 0; i < numbers_B+1; i++){
		mat[0][i] = 0;
		mirr[0][i] = 0;
	}
	for(i = 1; i < numbers_A+1; i++){
		for(j = 1; j < numbers_B+1; j++){
			if (A[i-1] == B[j-1]){
				mat[i][j] = mat[i-1][j-1] + 1;
				mirr[i][j] = 1;
			}else{
				mat[i][j] = fmax(mat[i-1][j],mat[i][j-1]);
				if(mat[i][j] == mat[i-1][j]){
					mirr[i][j] = 2;
				}else{
					mirr[i][j] = 3;
				}
			}
		}
	}
	fout<<mat[numbers_A][numbers_B]<<"\n";
	afiseaza(numbers_A,numbers_B);
	return 0;
	
}
