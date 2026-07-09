#include <stdio.h>
#include <fstream>

#define NMAX 1024

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int M,N, count = 0;
int v1[NMAX], v2[NMAX], sir[NMAX];

int theMax(int a, int b){
	if(a >= b)
		return a;
	return b;
}


void cmlsc(){

	int s = 1, m = M, n = N, nr = 0;

	while(s <= m && s <= n && v1[s] == v2[s]){
		sir[count++] = v1[s];
		nr++;
		s += 1;
	}
	while(s <= m && s <= n && v1[m] == v2[n]){
		sir[count++] = v1[m];
		nr++;
		m -= 1;
		n -= 1;
	}


	int l1 = m - s + 1, l2 = n - s + 1;
	int v[l1][l2];

	for(int i = 0; i <= l1; ++i)
		v[i][0] = 0;
	for(int i = 0; i <= l2; ++i)
		v[0][i] = 0;


	for(int i = s; i <= m; ++i){
		for(int j = s; j <= n; ++j){
			if(v1[i] == v2[j]){
	 			sir[count++] = v1[i]; 
	 			v[i-s+1][j-s+1] = v[i-s][j-s] + 1;
	 		}
	 		else
	 			v[i-s+1][j-s+1] = theMax(v[i-s+1][j-s],v[i-s][j-s+1]);
	 	}
	}

	// for(int i = 0; i < l1; ++i){
	// 	for(int j = 0; j < l2; ++j){
	// 		printf("%d ", v[i][j]);
	// 	}
	// 	printf("\n");
	// }

	out << v[m][n]+nr << "\n";
	for(int i = 0; i < v[m][n]+nr; ++i)
		out << sir[i] << " ";
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