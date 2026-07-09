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
	/*for(i=1;i<=m;i++)
	{	for(j=1;j<=n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}*/
	g<<a[m][n]<<endl;
	int val_crt=0,lin=1,col=1,stop;
	while(val_crt<a[m][n])
	{  val_crt++; stop=0;
	for(i=lin;i<=m&&!stop;i++)
		for(j=col;j<=n&&!stop;j++)
			if(a[i][j]==val_crt&&x[i]==y[j])
			{
				lin=i+1; col=j+1; g<<x[i]<<" "; stop=1; break;
			}
	}
	g.close();		
}
