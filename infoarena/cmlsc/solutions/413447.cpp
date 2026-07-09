#include <fstream>
using namespace std;

ifstream FIn("cmlsc.in");
ofstream FOut("cmlsc.out");

const int NMax=1<<10;
int N,M,A[NMax],B[NMax],PD[NMax][NMax];

inline int MAX(int a,int b){
	return a>b?a:b;
}

void IN(),OUT(),LUNGIMI(),REPRODUCERE_SUBSIR(int,int);
int main(){IN();LUNGIMI();OUT();return 0;}

void IN(){
	FIn>>N>>M;
	for(int i=1;i<=N;FIn>>A[i++]);
	for(int i=1;i<=M;FIn>>B[i++]);
}

void OUT(){
	FOut<<PD[N][M]<<"\n";
	REPRODUCERE_SUBSIR(N,M);
}

void LUNGIMI(){
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;PD[i][j]=((A[i]==B[j])?PD[i-1][j-1]+1:MAX(PD[i-1][j],PD[i][j-1])),++j);
	}
}

void REPRODUCERE_SUBSIR(int x,int y){
	if(!x||!y){
		return;
	}
	if(A[x]==B[y]){
		REPRODUCERE_SUBSIR(x-1,y-1);
		FOut<<A[x]<<" ";
		return;
	}
	if(PD[x-1][y]>=PD[x][y-1]){
		REPRODUCERE_SUBSIR(x-1,y);
		return;
	}
	REPRODUCERE_SUBSIR(x,y-1);
}
