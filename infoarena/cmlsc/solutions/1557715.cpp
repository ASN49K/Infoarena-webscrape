#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int M,N,A[1025],B[1025],sir[1025],D[1025][1025],rs; 
int main(){
	cin>>N>>M;
	for(int i = 1; i <= N; ++i) cin >> A[i]; 
	for(int j = 1; j <= M; ++j) cin >> B[j];
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <=M; ++j)
			if(A[i] == B[j]) D[i][j] = 1 + D[i-1][j-1];
		    else D[i][j] = max( D[i-1][j] , D[i][j-1]);
	for(int i = N, j = M; i != 0; )
	if(A[i] == B[j]) sir[++rs] = A[i], --i, --j;
    else if(D[i-1][j] < D[i][j-1]) --j;
	      else --i;	
    cout << rs << "\n";
	for(int i = rs; i != 0; --i)
		cout << sir[i] << " ";
	return 0;
}
