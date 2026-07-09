#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int c[1025][1025],i,j,n,m,a[1025],b[1025],maxn;
vector<int> buf;

int maxim(int x, int y)
{
	if(c[x-1][y] > c[x][y-1])
		return c[x-1][y];
	else
		return c[x][y-1];
}

int main()
{
	in>>n>>m;
	for(i=1; i<=n; i++)
		in>>a[i];
	for(i=1; i<=m; i++)
		in>>b[i];
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			if(a[i]==b[j])
				c[i][j] = maxim(i,j)+1;
			else
				c[i][j] = maxim(i,j);

	out<<c[n][m]<<'\n';
	maxn = c[n][m];
	for(i=n; i>=1; i--)
		for(j=m; j>=1; j--)
			if(maxn == c[i][j] && maxim(i,j)<c[i][j])
				{buf.push_back(a[i]);maxn--;}
	for(i=buf.size()-1; i>=0; i--)
		out<<buf[i]<<' ';
	return 0;
}
