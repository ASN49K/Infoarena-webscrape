#include<stdio.h>
#include<cstdlib>

#include<iostream>
#include<fstream>

using namespace std;

int M,N;
int A[1024],B[1024],C[1024];

int lcs(int* X, int n, int* Y, int m) {
	int** L=(int**)malloc((m+1)*sizeof(int*));
	for(int i=0;i<m+1;i++)
		L[i]=(int*)calloc(n+1,sizeof(int));
	
	int** dir=(int**)malloc((m+1)*sizeof(int*));
	for(int i=0;i<m+1;i++)
		dir[i]=(int*)calloc(n+1,sizeof(int));

	int diag=1, left=2, top=3;
	int* sequence=(int*)calloc(n+1,sizeof(int));
	int index=0;
	
	for (int i = 1; i <=m; i++) { // completare de sus in jos
		for (int j = 1; j <=n ; j++) { // completarea unei linii  
			if (X[j - 1] == Y[i - 1]){
				L[i][j] = L[i - 1][j - 1] + 1; 
				dir[i][j]=diag;
			}
			else{
				if(L[i - 1][j] >= L[i][j - 1]){
					 L[i][j]=L[i - 1][j]; 
					 dir[i][j]=top;
				}
				else{
					L[i][j]=L[i][j-1]; 
					dir[i][j]=left;
				}
			}
		}
	}

	int l=m, c=n, d = dir[l][c];
	while(d) {
		if (dir[l][c] == diag) {
			sequence[index++]=X[c-1]; 
			l--; c--; 
		} 
		else{	
			if (dir[l][c] == left) c--;
			else l--; 	
		}
		d = dir[l][c];
	}

	int len=L[m][n];

	for(int i=0;i<index;i++){
		C[i]=sequence[index-i-1];
	}

	free(L);
	free(dir);
	free(sequence);

	return len;
}

int main(){	
	int i;
	ifstream input("cmlsc.in" );
	ofstream output("cmlsc.out",std::ios::out);
	input >> M >> N;
	for(i=0;i<M;i++){
		input >> A[i];
	}
	for(i=0;i<N;i++){
		input >> B[i];
	}

	int l=lcs(A,M,B,N);
	output << l << endl;
	for(int i=0;i<l;i++)
		output << C[i] << " ";

	input.close();
	output.close();
	return 0;
}