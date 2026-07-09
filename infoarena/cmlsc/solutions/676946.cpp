#include<fstream>
using namespace std;
#define NMAX 1030

int n,m;
int a[NMAX],b[NMAX];
int cmlsc[NMAX][NMAX];
int sol[NMAX];

void read()
{
 int i;
 ifstream fin("cmlsc.in");
 fin>>n>>m;
 for (i=1; i<=n; ++i)
	 fin>>a[i];
 for (i=1; i<=m; ++i)
	 fin>>b[i];
 fin.close();
}

void solve()
{
 int i,j;
 for (i=1; i<=n; ++i)
	 cmlsc[i][0] = 0;
 for (j=1; j<=m; ++j)
	 cmlsc[0][j] = 0;

 for (i=1; i<=n; ++i)
	 for (j=1; j<=m; ++j)
		 if (a[i] == b[j])
			 cmlsc[i][j] = cmlsc[i-1][j-1] + 1; else
			 cmlsc[i][j] = max(cmlsc[i-1][j], cmlsc[i][j-1]);
}

void write()
{
 int i,nr,lin,col;
 ofstream fout("cmlsc.out");
 fout<<cmlsc[n][m]<<'\n';

 nr = cmlsc[n][m]; lin = n; col = m;
 while (nr)
	{
	 if (a[lin] == b[col])
		{
		 sol[nr] = a[lin];
		 lin--;
		 col--;
		 nr--;
		} else
		if (cmlsc[lin-1][col] > cmlsc[lin][col-1])
			lin--; else
			col--;
	}
 for (i=1; i<=cmlsc[n][m]; ++i)
	 fout<<sol[i]<<" ";
 fout<<'\n';
 fout.close();
}

int main()
{
 read();
 solve();
 write();
 return 0;
}
