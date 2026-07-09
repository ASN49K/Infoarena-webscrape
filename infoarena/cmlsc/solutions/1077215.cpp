#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,j,n,m,inainte,p,k,a[1026],b[1026],ap[258],viz[1026],maxim,var;
int main ()
{
	f>>n>>m;
	for (i=1;i<=n;i++)
		f>>a[i];
	for (i=1;i<=m;i++)
	{
		f>>b[i];
		ap[b[i]]=i;
	}
	for (i=1;i<=n-1;i++)
		{
			if (!viz[i])
			{
				inainte=i;
				if (ap[a[inainte]])
				{
					p++;
					k=0;
					viz[i]=p;
					for	(j=i+1;j<=n;j++)
						if (ap[a[j]]>ap[a[inainte]]&&ap[a[j]]) 
						{
							viz[j]=p;
							inainte=j;
							k++;
						}
					if (k+1>maxim)
					{
						maxim=k+1;
						var=p;
					}
				}
			}
		}
	g<<maxim<<"\n";
	for (i=1;i<=n;i++)
		if (viz[i]==var) g<<a[i]<<" ";
}