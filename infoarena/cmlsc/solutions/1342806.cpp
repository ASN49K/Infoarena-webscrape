// cel mailung subsir comun
#include<iostream>
#include<fstream>
#define max(a,b) (a>b)? a:b
using namespace std;
int a[1025],b[1025],c[1025][1025],n,m,sol[1025],k;
	ofstream fout("cmlsc.out");
	ifstream fin("cmlsc.in");
void afisare(int i,int j)
{

	k=c[n][m];
	while(k>0)
	{ 
	   while(a[i]!=b[j])
	      if (c[i-1][j]>c[i][j-1]) i--; else j--;
	

	 sol[k]=a[i];
	 i--;j--;
	 k--;
	
	}
	k=c[n][m];
for(i=1;i<=k;i++)
  fout<<sol[i]<<" ";
  fout.close();
}

int main()
{


int i,j;
	fin>>n>>m;
	for(i=1;i<=n;++i)
	fin>>a[i];
	 for(j=1;j<=m;++j)
	 fin>>b[j];
	for(i=1;i<=n;++i)

	for(j=1;j<=m;++j)
	 if(a[i]==b[j])   c[i][j]=c[i-1][j-1]+1;
	 else
	 c[i][j]=max(c[i][j-1],c[i-1][j]);

fout<<c[n][m]<<"\n";
afisare(n,m);
return 0;}
