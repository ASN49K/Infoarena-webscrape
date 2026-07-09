#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int refac(int &k,int i, int j, int a[1050], int b[1050],int mat[1050][1050],int c[1050])
{
if(i==0 || j==0)
	return 0;
if(a[i]==b[j])
	{c[k]=a[i];
	 k++;
	 refac(k,i-1,j-1,a,b,mat,c);
	 return 1;
	}
else if(mat[i-1][j]>mat[i][j-1])
		refac(k,i-1,j,a,b,mat,c);
	 else refac(k,i,j-1,a,b,mat,c);
}

int mat[1050][1050],a[1050],b[1050],c[1050];
int main()
{int n,m,i,j,k=1;
f>>n>>m;
for(i=1;i<=n;i++)
	f>>a[i];
for(i=1;i<=m;i++)
	f>>b[i];
for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		{if(a[i]==b[j])
			mat[i][j]=1+mat[i-1][j-1];
 		 else if(mat[i-1][j]>mat[i][j-1])
			mat[i][j]=mat[i-1][j];
		 else mat[i][j]=mat[i][j-1];
		}
g<<mat[n][m]<<endl;
refac(k,n,m,a,b,mat,c);
for(i=k-1;i>=1;i--)
	g<<c[i]<<" ";
return 0;}