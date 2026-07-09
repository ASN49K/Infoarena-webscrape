#include<fstream.h>
#include<iostream.h>
 //unsigned char a[1025][1025],b[1025][1025];
short int a[1025][1025],b[1025][1025];
 int  x[1025],y[1025];
ofstream g("cmlsc.out");
void scrie_CMLSC(int i,int j)
{
	if(i>0&&j>0)
		switch(b[i][j])
		{
		case 1:scrie_CMLSC(i-1,j-1);
		       g<<x[i]<<' ';
			   break;
	case 2:scrie_CMLSC(i-1,j);
		       break;
	case 3: scrie_CMLSC(i,j-1);
		}
}
		
int main()
{
	cout<<sizeof(short int);
	ifstream f("cmlsc.in");
	int n,m,i,j;
	f>>n>>m;
	for(i=1;i<=n;i++)f>>x[i];
	for(j=1;j<=m;j++)f>>y[j];
	for(i=0;i<=n;i++)a[i][0]=0;
	for(j=1;j<=m;j++)a[0][j]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(x[i]==y[j])
				{
					a[i][j]=a[i-1][j-1]+1;
					b[i][j]=1;
				}
			else if(a[i-1][j]>a[i][j-1])
					{
						a[i][j]=a[i-1][j];
						b[i][j]=2;
					}
			    else {
						a[i][j]=a[i][j-1];
						b[i][j]=3;
					 }
	//g<<(int)a[n][m]<<'\n';
	g<<a[n][m]<<'\n';
	scrie_CMLSC(n,m);
	g<<'\n';
}
			
			
			