#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

void pd();

int n, m;
int a[1025], b[1025];
int Lcs[1025][1025], x[1025][1025];

int main()
{
	int i, j;
	fin>>n>>m;
	for(i=0;i<n;i++)
		fin>>a[i];
	for(i=0;i<m;i++)
		fin>>b[i];
	pd();
	i=j=0;
	fout<<Lcs[i][j]<<'\n';
	while(i<n && j<m)
	{
		if(x[i][j]==1)
		{
			fout<<a[i]<<' ';
			i++;
			j++;
		}
		if(x[i][j]==2)
			i++;
		if(x[i][j]==3)
			j++;
	}
	return 0;
}

void pd()
{
	int i, j;
	for(i=n-1;i>=0;i--)
		for(j=m-1;j>=0;j--)
			if(a[i]==b[j])
			{
				Lcs[i][j]=1+Lcs[i+1][j+1];
				x[i][j]=1;
			}
			else
			{
				if(Lcs[i+1][j]>Lcs[i][j+1])
				{
					Lcs[i][j]=Lcs[i+1][j];
					x[i][j]=2;
				}
				else
					if(Lcs[i+1][j]<Lcs[i][j+1])
					{
						Lcs[i][j]=Lcs[i][j+1];
						x[i][j]=3;
					}
			}
}
