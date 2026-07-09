#include<fstream.h>

int a[1050],b[1050],c[1050][1050],n,m,d[1050],p;


ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int max(int x,int y)
{	if(x>y)return x ;
	return y;
}

void cmlsc()
{	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		if(a[i]==b[j] && i<=j)
			       {  c[i][j]=c[i-1][j-1]+1; d[++p]=a[i];
			       }
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
  /*	for(i=1;i<=n;i++)
	{	for(j=1;j<=m;j++)
			g<<c[i][j]<<" ";
			g<<endl;
	}
   */
	g<<c[n][m]<<"\n";
	for(i=1;i<=p;i++)
		g<<d[i]<<" ";
                g<<"\n";
	f.close();
	g.close();
	return 0;
}