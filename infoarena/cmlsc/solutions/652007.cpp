#include <iostream>
#include <fstream>
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a < b ? b : a)

using namespace std;

int matrice[1025][1025];

int main()
{
	ifstream f1("cmlsc.in");
	ofstream f2("cmlsc.out");
	int M,N,i,j;
	f1>>M>>N;
	int A[M],B[N];
	for(i=0;i<M;i++)
		f1>>A[i];
	for(i=0;i<N;i++)
		f1>>B[i];
	for(i=1;i<=M;i++) {
		for(j=1;j<=N;j++) {
			if(A[i-1]==B[j-1]) {
				matrice[i][j] = matrice[i-1][j-1]+1;
			}
			else {
				matrice[i][j] = MAX(matrice[i-1][j], matrice[i][j-1]);
			}
		}
	}
	f2<<matrice[M][N]<<"\n";
	int rez[MIN(M,N)],z = 0;
	while(M>0 && N>0) {
		if(A[M-1] == B[N-1]) {
			rez[z] = A[M-1];
			M--;
			N--;
			z++;
		}
		if(matrice[M-1][N] > matrice[M][N-1]) {
			M--;
		}
		else
			N--;
	}	
	for(i=z-1;i>=0;i--) {
		f2<<rez[i]<<" ";		
	}
}