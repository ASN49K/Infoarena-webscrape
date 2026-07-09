#include <stdio.h>
#include <fstream>

#define NMAX 1024

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int M,N, count = 0;
int v1[NMAX], v2[NMAX], v[NMAX][NMAX], sol[NMAX];

int theMax(int a, int b){
	if(a >= b)
		return a;
	return b;
}


void bkt(int v1[NMAX], int v2[NMAX], int v[NMAX][NMAX], int i, int j){
	if(i == 0 || j == 0){
		for(int k = v[M][N]-1; k >= 0 ; --k)
			out << sol[k] << " ";
		return;
	}
	else if(v1[i] == v2[j]){
		sol[count++] = v1[i];
		bkt(v1,v2,v,i-1,j-1);
	}
	else{
		if(v[i][j-1] > v[i-1][j])
			bkt(v1,v2,v,i,j-1);
		else
			bkt(v1,v2,v,i-1,j);
	}
}


void cmlsc(){

	
	for(int i = 0; i <= M; ++i)
		v[i][0] = 0;
	for(int i = 0; i <= N; ++i)
		v[0][i] = 0;



	for(int i = 1; i <= M; ++i){
		for(int j = 0; j <= N; ++j){
			if(v1[i] == v2[j])
				v[i][j] = v[i-1][j-1] + 1;
			else
				v[i][j] = theMax(v[i][j-1],v[i-1][j]);
		}
	}

	out << v[M][N] << "\n";

	bkt(v1,v2,v,M,N);
}

int main(){

	in >> M >> N;
	
	for(int i = 1; i <= M; ++i)
		in >> v1[i];
	
	for(int i = 1; i <= N; ++i)
		in >> v2[i];

	cmlsc();

	return 0;
}