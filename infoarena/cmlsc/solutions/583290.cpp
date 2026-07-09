#include <fstream>
using namespace std;

int a[1024],b[1024],nr;
bool c[1024][1024],l[1024];
int n,m;

int main()
{
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int i1,i2;

in>>n>>m;
for(i1=0;i1<n;i1++)
	in>>a[i1];
for(i1=0;i1<n;i1++)
	in>>b[i1];

for(i1=0;i1<n;i1++)
	for(i2=0;i2<m;i2++)
		{
		if(a[i1] == b[i2])
			l[i1]=true;
		}
for(i1=0;i1<n;i1++)
	{
	if(l[i1])
		nr++;
	}
out<<nr<<'\n';
for(i1=0;i1<n;i1++)
	{
	if(l[i1])
		out<<a[i1]<<' ';
	}

in.close();
out.close();
return 0;
}