#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int refac(int i, int j, int a[1050], int b[1050],int mat[1050][1050])
{
if(i==0 || j==0)
	return 0;
if(a[i]==b[j])
	{g<<a[i]<<" ";
	 refac(i-1,j-1,a,b,mat);
	}
else if(mat[i-1][j]>mat[i][j-1])
		refac(i-1,j,a,b,mat);
	 else refac(i,j-1,a,b,mat);
}

int mat[1050][1050],a[1050],b[1050];
int main()
{int n,m,i,j;
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
refac(n,m,a,b,mat);
return 0;}