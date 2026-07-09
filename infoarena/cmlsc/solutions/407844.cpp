#include <iostream>
#include <fstream>
int a[1025][1025];

using namespace std;

int main()
{
	fstream f("cmlsc.in",ios::in), g("cmlsc.out",ios::out);
	int m,n,i,j,x[1025],y[1025];
	f>>m>>n;
	for(i=1;i<=m;i++)
		f>>x[i];
	for(j=1;j<=n;j++)
		f>>y[j];
	f.close(); 
	
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(x[i]==y[j])
				a[i][j]=1+a[i-1][j-1];
			else
				if(a[i-1][j]>a[i][j-1])
					a[i][j]=a[i-1][j];
				else
					a[i][j]=a[i][j-1];
	
	g<<a[m][n]<<endl;
	int nr=0,sol[1025];
	for(i=m,j=n;i>=1;)
	{
		if(x[i]==y[j])
		{	
			sol[++nr]=x[i];
			i--; j--;
		}
		else
			if(a[i-1][j]<a[i][j-1])
				j--;
			else
				i--;
	}
	for(i=nr;i>=1;i--)
		g<<sol[i]<<" ";
	g.close();		
}
