#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,A[1025],B[1025];
int L[1025][1025],sol[1025];

int main(void){
	register int i,j;
	
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>A[i];
	for(i=1;i<=m;i++)
		f>>B[i];
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(A[i]==B[j])
				L[i][j]=L[i-1][j-1]+1;
			else{
				L[i][j]=(L[i-1][j]>L[i][j-1]?L[i-1][j]:L[i][j-1]);
			}
		}
	}
	
	g<<L[n][m]<<"\n";
	
	for(i=n,j=m;i>0 && j>0;){
		if(A[i]==B[j])
			sol[++sol[0]]=A[i],--i,--j;
		else if(L[i-1][j]>L[i][j-1])
			i--;
		else
			j--;
	}
	
	for(i=sol[0];i>0;i--)
		g<<sol[i]<<" ";
	f.close();
	g.close();
	return 0;
}