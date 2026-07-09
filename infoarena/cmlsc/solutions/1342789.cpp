// cel mailung subsir comun
#include<iostream>
#include<fstream>
#define max(a,b) (a>b)? a:b
using namespace std;
int a[1025],b[1025],c[1025][1025],n,m,sol[1025],k;

void afisare(int i,int j)
{
	ofstream cout("cmlsc.out");
	k=c[n][m];
	while(k>0)
	{ sol[k]=c[i][j];
	   while(c[i][j]!=c[i-1][j-1]+1)
	      if (c[i-1][j]>c[i][j-1]) i--; else j--;
	
	 i--;j--;
	 sol[k]=a[i];
	 k--;
	
	}
	k=c[n][m];
for(i=1;i<=k;i++)
  cout<<sol[i]<<" ";
}

int main()
{
ifstream cin("cmlsc.in");

int i,j;
	cin>>n>>m;
	for(i=1;i<=n;++i)
	cin>>a[i];
	 for(j=1;j<=m;++j)
	 cin>>b[j];
	for(i=1;i<=n;++i)
{
	for(j=1;j<=m;++j)
	 if(a[i]==b[j])   
	                   c[i][j]=c[i-1][j-1]+1;
	 else
	 c[i][j]=max(c[i][j-1],c[i-1][j]);
}
cout<<c[n][m]<<"\n";
afisare(n,m);
return 0;}
