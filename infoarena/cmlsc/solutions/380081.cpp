#include <vector>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

short n,m,i,j,x[1025][1025],a[1025],b[1025],k;
vector<short> cmlsc;

int main()
{
	in>>n>>m;
	for(i=1; i<=n; i++)
		in>>a[i];
	for(j=1; j<=m; j++)
		in>>b[j];
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
		{
			k = (x[i-1][j]>x[i][j-1])?x[i-1][j]:x[i][j-1];
			if(k==1)
					k=k;
			x[i][j] = int(a[i]==b[j])+k;
		}

	k = 1;
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			if(x[i][j] == k)
			{
				cmlsc.push_back(a[i]);
				k++;
			}
	out<<cmlsc.size()<<'\n';
	vector<short>::iterator it = cmlsc.begin();
	for(; it!=cmlsc.end(); it++)
		out<<*it<<' ';

	return 0;
}