#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1024],b[1024],c[1024][1024],t[1024];

int m,n,k=0,i,j;

int main()
{
	fin>>m>>n;
	for(i=1;i<=m;i++)
		fin>>a[i];
	for(i=1;i<=n;i++)
		fin>>b[i];
	
	for(i = 1;i<=m;i++)
	{	for(j=1;j<=n;j++)
		{
			if(a[i]==b[j])
				c[i][j] = c[i-1][j-1]+1;
			else
			{
				if(c[i-1][j] > c[i][j-1])
					c[i][j] = c[i-1][j];
				else
					c[i][j] = c[i][j-1];
			}
		}
	}
	for (i = m, j = n; i; )
        if (a[i] == b[j])
            t[++k] = a[i], --i, --j;
        else if (c[i-1][j] < c[i][j-1])
            --j;
        else
            --i;

    fout<< k<<'\n';
    for (i = k; i; --i)
		fout<<t[i]<<' ';
	return 0;
}
		