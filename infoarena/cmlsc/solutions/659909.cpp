#include <fstream>
#define maxim(a, b) ((a > b) ? a : b)
using namespace std;
ifstream f("cmlsc.in"); ofstream g("cmlsc.out");
int i,j,N,M;
int A[1024],B[1024],D[1024][1024],sir[1024],bst;
int main(){
	f>>N>>M; for(i=1;i<=N;i++)f>>A[i]; for(i=1;i<=M;i++)f>>B[i];
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			if(A[i]==B[j])
				D[i][j]=1+D[i-1][j-1];
			else 
				D[i][j]=maxim(D[i-1][j],D[j][i-1]);
	for(i=N,j=M;i;){
		if(A[j]==B[i])
			sir[++bst]=A[j],--i,--j;
		else if(D[j-1][i]<D[j][i-1])
			j--;
		else
			i--;
	}
	g<<bst<<'\n';
	for(i=bst;i;i--)
		g<<sir[i]<<' ';
	g.close(); return 0;
}
