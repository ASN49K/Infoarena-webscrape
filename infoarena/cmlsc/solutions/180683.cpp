#include<fstream.h>

long int a[1025],b[1025],c[1025][1025],d[1050];
long int n,m,p;


ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int max(int x,int y)
{	if(x>y)return x ;
	return y;
}

void cmlsc()
{	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1; 
		else c[i][j]=max(c[i-1][j],c[i][j-1]);

}
int main()
{	f>>n>>m ;
	int i,j;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	cmlsc();
	int p=0;
	
  	for(i=n;i>=1;)
	for(j=m;j>=1;)
		if(a[i]==b[j]) {	d[++p]=a[i];
					i--;
					j--;
			       }
		else  if(c[i-1][j]<=c[i][j-1]) j--;
		else  	i--;
	g<<c[n][m]<<"\n";
	for(i=p;i>=1;i--)
	g<<d[i]<<" ";
	g<<"\n";
  
	
	
	f.close();
	g.close();
	return 0;
}