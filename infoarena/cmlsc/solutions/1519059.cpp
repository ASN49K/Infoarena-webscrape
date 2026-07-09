#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

#define DIVISOR 666013

using namespace std;

ifstream in("kfib.in");
ofstream out("kfib.out");


void MMultiply(long long A[2][2], long long B[2][2], long long rez[2][2]){


	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			rez[i][j] = 0;

	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			for(int k = 0; k < 2; ++k)
				rez[i][j] = (rez[i][j] + A[i][k]*B[k][j]) % DIVISOR;
}



void copy2D(long long M[2][2], long long r[2][2]){

	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			r[i][j] = M[i][j];
}



void MtrxLgPow(long long Z[2][2], long long P, long long rez[2][2]){

	long long Y[2][2] = {{1,0},{0,1}};

	long long tmp[2][2];


	while(P >= 1){
		
		if(P % 2 == 1){
			MMultiply(Y,Z,tmp);
			copy2D(tmp,Y);
			P -= 1;
		}

		MMultiply(Z,Z,tmp);
		copy2D(tmp,Z);
		P /= 2;
	}
	
	copy2D(Y,rez);
}


long long KFib(int k){

	long long Z[2][2] = {{0,1},{1,1}};
	long long rez[2][2];

	MtrxLgPow(Z,k-1, rez);

	return rez[1][1];
}


int main(){


	int k;
	in >> k;

	out << KFib(k) << "\n";
	return 0;
}