#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,a[1025],b[1025],x[1025][1025],sol[1025],i,j,k;
int main()
	{f>>m>>n;
	for(i=1;i<=m;i++) f>>a[i];
	for(i=1;i<=n;i++) f>>b[i];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j]) x[i][j]=1+x[i-1][j-1];
				else if(x[i][j-1]>x[i-1][j]) x[i][j]=x[i][j-1];
					else x[i][j]=x[i-1][j];
	g<<x[m][n]<<'\n';
	i=m; j=n;
	while(i>0 && j>0)
		if(a[i]==b[j]) {sol[++k]=a[i]; i--;j--;}
			else if(x[i][j-1]>x[i-1][j]) j--;
				else i--;
	for(i=k;i>0;i--) g<<sol[i]<<" ";
	f.close();
	g.close();
	return 0;}
	