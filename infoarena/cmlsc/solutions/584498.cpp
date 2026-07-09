#include <fstream>
using namespace std;

int la,lb,lmax=1;
int a[1025],b[1025];
int v[1025][1025];
int maxk,maxm,vmax[1025];

int main()
{
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int i1,i2,i3,i4;

in>>la>>lb;
for(i1=1;i1<=la;i1++)
	in>>a[i1];
for(i1=1;i1<=lb;i1++)
	in>>b[i1];

for(i1=1;i1<=la;i1++)
	for(i2=1;i2<=lb;i2++)
		if(a[i1] == b[i2])
			{
			maxk = 0;
			for(i3=1;i3<i1;i3++)
				for(i4=1;i4<i2;i4++)
					if(v[i3][i4] > maxk)
						maxk = v[i3][i4];
			v[i1][i2] = maxk + 1;
			if(v[i1][i2] > maxm)
				{
				vmax[lmax]=a[i1];
				lmax++;
				maxm = v[i1][i2];
				}
			}
out<<maxm<<'\n';
for(i1=1;i1<lmax;i1++)
	out<<vmax[i1]<<' ';

/*
for(i1=0;i1<=la;i1++)
	{
	for(i2=0;i2<=lb;i2++)
		printf("%d ",v[i1][i2]);
	printf("\n");
	}
*/
in.close();
out.close();
return 0;
}