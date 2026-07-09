// cel mailung subsir comun
#include<iostream>
#include<fstream>
#define max(a,b) (a>b)? a:b
using namespace std;
int a[1025],b[1025],c[1025][1025],n,m,sol[1025];

int main()
{
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int i,j,k=0;
	cin>>n>>m;
	for(i=1;i<=n;++i)
	cin>>a[i];
	 for(j=1;j<=m;++j)
	 cin>>b[j];
	for(i=1;i<=n;++i)
{
	for(j=1;j<=m;++j)
	 if(a[i]==b[j]) {   k++;sol[k]=a[i];
	                   c[i][j]=c[i-1][j-1]+1;}
	 else
	 c[i][j]=max(c[i][j-1],c[i-1][j]);
}
cout<<c[n][m]<<"\n";
for(i=1;i<=k;++i)
  cout<<sol[i]<<" ";
return 0;}
