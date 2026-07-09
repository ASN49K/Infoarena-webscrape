#include <fstream>
using namespace std;

int na,nb;
int a[1025],b[1025],ret[1025],maxm;
int v[1025][1025];

int main()
{
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int i1,i2;

in>>na>>nb;
for(i1=1;i1<na+1;i1++)
	in>>a[i1];
for(i1=1;i1<nb+1;i1++)
	in>>b[i1];

for(i1=1;i1<na+1;i1++)
	for(i2=1;i2<nb+1;i2++)
		{
		if(a[i1] == b[i2])
			{
			v[i1][i2] = v[i1-1][i2-1] + 1;
			if(v[i1][i2] > maxm)
				{
				maxm = v[i1][i2];
				ret[maxm] = a[i1];
				}
			}
		else
			if(v[i1-1][i2] > v[i1][i2-1])
				v[i1][i2] = v[i1-1][i2];
			else
				v[i1][i2] = v[i1][i2-1];
		}
out<<maxm<<'\n';
for(i1=1;i1<maxm+1;i1++)
	out<<ret[i1]<<' ';

in.close();
out.close();
return 0;
}