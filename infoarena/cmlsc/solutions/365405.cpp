#include<fstream>
#define N 1030
using namespace std;
ifstream f1("cmlsc.in");
ofstream f2("cmlsc.out");
int A[N],B[N],D[N][N],sir[N];
int main()
{
	int i,j,m,n,nr=0;
	f1>>m>>n;
	for (i=1; i<=m; i++) f1>>A[i];
	for (i=1; i<=n; i++) f1>>B[i];
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
			if (A[i]==B[j]) D[i][j]=D[i-1][j-1]+1;
			else D[i][j]=max(D[i-1][j],D[i][j-1]);
	for (i=m, j=n; i;)
		if (A[i]==B[j]) {sir[++nr]=A[i]; i--; j--;}
		 else if (D[i-1][j]<D[i][j-1])  j--; else i--;
	f2<<nr<<"\n";
	for (i=nr; i>=1; i--) f2<<sir[i]<<" ";
	return 0;
}