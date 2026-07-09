#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,a[1025],b[1025],k=1,maxim=0,i,j,v[1025];
int main()
{
	v[0]=0;
	f>>m>>n;
	for(i=1;i<=m;i++)
		f>>a[i];
	for(j=1;j<=n;j++)
		f>>b[j];
	f.close();
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				if(a[i]>v[k-1])
					{
						v[k]=a[i];
						k++;
						maxim++;
				}
	g<<maxim<<"\n";
	for(i=1;i<k;i++)
		g<<v[i]<<" ";
	g.close();
	return 0;
}
