#include <stdio.h>
#include <fstream>

#define NMAX 1024

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int M,N, count = 0;
int v1[NMAX], v2[NMAX], v[NMAX][NMAX], sir[NMAX];



void cmlsc(){

	for(int i = 0; i <= M; ++i)
		v[i][0] = 0;
	for(int i = 0; i <= N; ++i)
		v[0][i] = 0;

	for(int i = 1; i <= M; ++i){
		for(int j = 1; j <= N; ++j){
			if(v1[i] == v2[j])
				sir[count++] = v1[i];
		}
	}

	out << count << "\n";
	for(int i = 0; i < count; ++i)
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