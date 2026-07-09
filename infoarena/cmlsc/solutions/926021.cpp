#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int N, M;
int C[1025][1025];
int A[1024], B[1024];

void read(){
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	cin >> M >> N ;
	for(int i = 0; i < M ; i ++ ){
		cin >> A[i];
	}

	for(int j = 0; j < N; j++){
		cin >> B[j];
	}
}

int computeLCS(){
	memset(C, 0, sizeof(C));
	for(int i = 1; i <= M; i++){
		for(int j = 1; j <= N; j++){
			if(A[i - 1] == B[j - 1]){
				C[i][j] = C[i-1][j-1] + 1;
			}else{
				C[i][j] = max(C[i-1][j], C[i][j-1]);
			}
		}
	}
	return C[M][N];
}

string recomposeSequence(int i, int j){
	if(i == 0  || j == 0){
		return "";
	}else{
		if(A[i - 1] == B[j - 1]){
			const char com = A[i - 1] + '0';
			return	recomposeSequence(i-1, j- 1) + com + " ";
		}else{
			if(C[i-1][j] > C[i][j-1]){
				return recomposeSequence(i-1, j);
			}else
				return recomposeSequence(i, j-1);
		}
	}
}


int main(){
	read();
	cout << computeLCS() << endl;
	cout << recomposeSequence(M, N) << endl;
	cout.flush();
	return 0;
}

