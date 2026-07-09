#include<iostream>
#include<fstream>
using namespace std;
#define MAX_N 1500

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

int maxim(int x,int y,int z){
	int max = x;
	if( max < y )
		max = y;
	if(max < z)
		max =z;
	
	
	return max;

}

void LCS(){
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			int max = maxim(mat[i-1][j], mat[i][j-1], mat[i-1][j-1]);
			if(a[i] ==  b[j]){
				mat[i][j] = max +1;
			}else{
				mat[i][j] = max;
			}
		}
	}

}

ofstream g ("cmlsc.out");
void afis(int col, int ant ){
	int poz = 1;
	if(col>=1 && ant!=1){
		int max = mat[1][col];
		for(int i=2;i<=N; i++){
			if(mat[i][col]>max && mat[i][col]<ant)
				max = mat[i][col], poz=i;
		}
		
		afis(col-1, max);
		g << a[poz] << " ";
	}
	
}

int main(){
	
	read();
	LCS();
	g << mat[N][M] <<'\n';
	afis(M, mat[N][M]+1);
	


	return 0;
}
