#include <fstream>
std::ifstream f1("cmlsc.in");
std::ofstream f2("cmlsc.out");
int sol[1030][1030], a[1030], b[1030], subsir[1030];
int main()
{
	int i, j, n, m, poz=0;
	f1>>n>>m;
	for (i=1; i<=n; i++)
		f1>>a[i];
	for (i=1; i<=m; i++)
		f1>>b[i];
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
			if (a[i]==b[j])
				sol[i][j]=sol[i-1][j-1]+1;
			else
				if (sol[i-1][j]>sol[i][j-1])
					sol[i][j]=sol[i-1][j];
				else
					sol[i][j]=sol[i][j-1];
	f2<<sol[n][m]<<"\n";
	i=n;
	j=m;
	while ((i>0)&&(j>0))
	{
		if (a[i]==b[j])
		{
			subsir[poz++]=a[i];
			i--;
			j--;
		}//if
		else
			if (sol[i-1][j]>sol[i][j-1])
				i--;
			else
				j--;
	}//while
	for (i=poz-1; i>=0; i--)
		f2<<subsir[i]<<" ";
	f1.close();
	f2.close();
	return 0;
}//main
