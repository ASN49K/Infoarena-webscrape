#include <iostream.h>
#include<fstream.h>
int x[1030][1030],sol[1030];
int main()
{
int s=0,a[1030],b[1030],m,n,i,j;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
in>>m>>n;
for (i=1;i<=m;++i)
	in>>a[i];
for(i=1;i<=n;++i)
	in>>b[i];
for(i=1;i<=m;i++)
	for (j=1;j<=n;j++)
		if (a[i]==b[j])
			x[i][j]=1+x[i-1][j-1];
		else
			if (x[i-1][j]>x[i][j-1]) x[i][j]=x[i-1][j];
				else x[i][j]=x[i][j-1];
out<<x[m][n];
i=m;
j=n;
while (i&&j)
	{
	if (a[i]==b[j])
		{
		sol[++s]=a[i];
		i--;
		j--;
		}
	else
	if (x[i-1][j]>x[i][j-1])
		i--;
	else
		j--;
	}
for (i=s;i>=1;i--)
	out<<sol[i];
out<<endl;
return 0;
}
