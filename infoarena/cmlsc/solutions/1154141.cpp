#include <fstream>
#include <math.h>

#define MAX 1025

using namespace std;

int matrix[MAX][MAX];

int main(){

	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");

	int n1, n2;
	fin >> n1 >> n2; 

	int s1[MAX], s2[MAX];

	for (int i = 0; i <= n1; i++){
		if(i >= 1)
			fin >> s1[i-1];
		matrix[i][0] = 0;
	}
	for(int j = 0; j <= n2; j++){
		if(j >= 1)
			fin >> s2[j-1];
		matrix[0][j] = 0;
	}

	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n2; j++){
			if(s1[i-1] == s2[j-1])
				matrix[i][j] = matrix[i-1][j-1] + 1;
			else
				matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
		}
	}

	fout<<matrix[n1][n2]<<"\n";
	int c = matrix[n1][n2], i = n1, j = n2, results[MAX], copy = c;
	while(c){
		if(matrix[i][j] == max(matrix[i-1][j], matrix[i][j-1])){
			if(matrix[i][j] == matrix[i-1][j]) i--;
			if(matrix[i][j] == matrix[i][j-1]) j--;
		}else{
			results[--c] = s1[i-1];
			i--;
			j--;
		}
	}
	for(i = 0; i < copy; i++){
		fout<<results[i]<<" ";
	}
	fout<<"\n";
	return 0;
}