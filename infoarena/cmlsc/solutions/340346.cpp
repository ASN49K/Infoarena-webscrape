#include<fstream.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
void program(int i,int j,int a[10],int b[10],int n,int m,int &max,int c[10])
{
	if(i<=n)
	{
		if(a[i]==b[j])
			{
				max++;
				c[max]=a[i];
				program(i+1,j+1,a,b,n,m,max,c);
			}
		else
				if(j==m) program(i+1,1,a,b,n,m,max,c);
				else
			{
				program(i,j+1,a,b,n,m,max,c);
			}
	}
}
int main()
{
	int n,m,nc=0;
	f>>n>>m;
	int a[1025],b[1025],c[1025];
	for(int i=1;i<=n;i++) f>>a[i];
	for(i=1;i<=m;i++) f>>b[i];
	program(1,1,a,b,n,m,nc,c);
	g<<nc<<'\n';
	for(i=1;i<=nc;i++) g<<c[i]<<" ";
	return 0;
}