#include<fstream>
using namespace std;
int a[256],b[256],s[256],n,m,i,j,nr,x,max0,max1;
int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>n>>m;
	for(i=1;i<=n;i++)
	{
		f>>x;
		a[x]=x;
		if(x>max0)
			max0=x;
	}
	for(i=1;i<=m;i++)
	{
		f>>x;
		b[x]=x;
		if(x>max1)
			max1=x;
	}
	if(m<n)
	{
		for(i=1;i<=max1;i++)
			if(b[i]!=0&&b[i]==a[i])
				s[++nr]=b[i];
	}
	else
	{
		for(i=1;i<=max0;i++)
			if(a[i]!=0&&a[i]==b[i])
				s[++nr]=a[i];
	}
	g<<nr<<"\n";
	for(i=1;i<=nr;i++)
		g<<s[i]<<" ";
	return 0;
}