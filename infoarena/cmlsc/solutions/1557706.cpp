#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int M,N,A[1025],B[1025],sir[1025],D[1025][1025],rs; 
int maxim(int a, int b){
	if(a>b) return a;
	else return b;
}
int main(){
	cin>>N>>M;
	for(int i = 1; i <= N; i++) cin>>A[i]; 
	for(int j = 1; j <= M; j++) cin>>B[j];
	for(int i=1; i <=N; i++)
		for(int j=1; j <=M; j++)
			if(A[i] == B[j]) D[i][j] = ++D[i-1][j-1];
		    else D[i][j ]= maxim(D[i][j-1] , D[i-1][j]);
	int i=N, j=M; 
	while(D[i][j]!=0){
	 if(A[i] == B[j]) {
	 sir[++rs]=A[i];
	 --j; --i;
	 }
	 else if(D[i-1][j] < D[i][j-1]) --j;
	      else --i;	
    } 
    cout<<rs<<"\n";
	for(int i = rs; i >= 1; i--)
		cout<<sir[i]<<" ";
	return 0;
}
