#include<fstream.h>
//using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int m,n,a[1025],j,b[1025],i,c[125][125],v[1025];

int main ()
{
	in>>n>>m;
	for(i=1;i<=n;i++)
			{
				in>>a[i];
				c[i][0]=0;
			}
	for(i=1;i<=m;i++)
			{
				in>>b[i];
				c[0][i]=0;
			}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			{
				if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
				else
					{
						if(c[i-1][j]>c[i][j-1])
							c[i][j]=c[i-1][j];
						else
							c[i][j]=c[i][j-1];
				}
		}
out<<c[n][m]<<"\n";
i=n; j=m;
int k=0;
int q=c[n][m];

while(q)
{

	if(a[i]==b[j])
	{
		v[++k]=a[i];
		i--;
		j--;

	}
	else
	{
		if(c[i-1][j]>c[i][j-1])
			{
			i--;

			}

		else
			{
			j--;

			}

	}

		if(k==q)
			q=0;
}
for(i=k;i>=1;i--)
	out<<v[i]<<" ";
return 0;
}