#include<iostream>
#include<fstream>
using namespace std;
#define MAX_N 1500
#define maxim(a,b) ((a>b)? a:b)
int N, M; // lungimile celor doua siruri
int a[MAX_N], b[MAX_N]; // cele doua siruri
int mat[MAX_N][MAX_N];

void read(){
	ifstream f("cmlsc.in");
	
	f >> N >> M;
	
	for(int i=1; i<=N; i++){
		f >> a[i];
	}
	for(int i=1; i<=M; i++){
		f >> b[i];
	}
}


void LCS(){
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(a[i] ==  b[j]){
				mat[i][j] = mat[i-1][j-1] +1;
			}else{
				mat[i][j] =maxim(mat[i-1][j], mat[i][j-1]);
			}
		}
	}

}

ofstream g ("cmlsc.out");

void afis(int size1, int size2 ){
	
	if(size1 and size2){
		if(a[size1] ==  b[size2]){
			afis(size1-1,size2-1);
			g<< a[size1] << " ";
		}else if(mat[size1-1][size2] > mat[size1][size2-1]){
			afis(size1-1, size2);
		}else afis(size1, size2-1);
	}
	
}

int main(){
	
	read();
	LCS();
	g << mat[N][M] <<'\n';
	afis(N, M);
	


	return 0;
}
