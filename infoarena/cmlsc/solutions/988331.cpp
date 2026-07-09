#include<fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int x[1029][1029];
int a[1029], b[1029];
int n,m;

void printSeq(int i, int j)
{
	if(i==0 || j==0)
		return;

	if(a[i] == b[j])
	{
		printSeq(i-1, j-1);
		out<<a[i]<<" ";
	}
	else
	{
		if(x[i-1][j] > x[i][j-1])
			printSeq(i-1, j);
		else if(x[i][j-1] >= x[i-1][j])
			printSeq(i, j-1);
	}
}


void cmlsc()
{
	for(int i=0; i<=n; i++)
		for(int j=0; j<=m; j++)
			x[i][j] = 0;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			if(a[i] == b[j])
			{
				x[i][j] = x[i-1][j-1] + 1;
			}
			else
			{
				if(x[i-1][j] > x[i][j-1])
					x[i][j] = x[i-1][j];
				else if(x[i][j-1] >= x[i-1][j])
					x[i][j] = x[i][j-1];
			}
		}

	out<<x[n][m]<<'\n';

	printSeq(n, m);
}


int main()
{

	in>>n>>m;

	for(int i=1; i<=n; i++)
		in>>a[i];
	for(int i=1; i<=m; i++)
		in>>b[i];

	in.close();

	cmlsc();

	out.close();
	return 0;

}


