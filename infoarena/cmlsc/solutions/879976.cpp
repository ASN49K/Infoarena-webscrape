#include<fstream>
#define dmax 1026
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, a[dmax], b[dmax], x[dmax][dmax];

int mx(int a, int b)
{
	if(a > b)
		return a;
	return b;
}	


void write(int i, int j)
{
	if(i > 0 && j > 0)
	{
		if(x[i][j] == x[i-1][j-1]+1)
		{	
			write(i-1, j-1);
			out<<a[i]<<" ";
		}	
		else if(x[i][j] == x[i-1][j])
			write(i-1, j);
		else write(i, j-1);
	}
}

int main()
{
	in>>n>>m;
	
	for(int i=1; i<=n; i++)
		in>>a[i];
	
	for(int i=1; i<=m; i++)
		in>>b[i];
	in.close();
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(a[i] == b[j])
			{
				x[i][j] = x[i-1][j-1] + 1;
			}
			else
			{
				if(x[i-1][j] > x[i][j-1])
				{
					x[i][j] = x[i-1][j];
				}
				else
				{
					x[i][j] = x[i][j-1];
				}	
			}
			
	out<<x[n][m]<<'\n';
	
	write(n, m);
	return 0;
}			