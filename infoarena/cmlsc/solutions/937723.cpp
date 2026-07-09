#include "iostream"
#include "fstream"
#define MAX(x,y) x>y?x:y
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main(){
	int n,m;
	
	f>>n>>m;
	
	
		int a[n+1],b[m+1],mat[n+1][m+1],sol[1025];
		int i,j,k=0;
		
		for (i=1;i<=n;i++){
			f>>a[i];
		}
		
		for (i=1;i<=m;i++){
			f>>b[i];
		}
		
		
		for (i=0;i<=n;i++){
			mat[i][0]=0;
		}
		
		for (j=0;j<=m;j++){
			mat[0][j]=0;
		}
		
	
		
			for (i=1;i<=n;i++)
				for (j=1;j<=m;j++)
						if (a[i]==b[j]){
								mat[i][j]=mat[i-1][j-1]+1;						
						}
						else
							{
								mat[i][j]=MAX(mat[i-1][j],mat[i][j-1]);		
							}
							

			i=n;
			j=m;
			while (i && j){
				
				if (a[i]==b[j]){
				sol[++k]=a[i];
				
				i--;
				j--;	
				}
						
				else
					if (mat[i][j-1]>mat[i-1][j])
							j--;
					else
							i--;
				
			}
			
	g<<mat[n][m]<<"\n";
	for (;k;k--)
		g<<sol[k]<<" ";
return 0;	
}