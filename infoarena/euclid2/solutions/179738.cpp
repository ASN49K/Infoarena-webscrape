#include <fstream.h>
ifstream fin("euclid2.in");
ofstram fout("euclid2.out");
void cmmdc(long a,long b);
{
if(!b) return(a);
else return cmmdc(b,a%b);
}
int main()
{
long m,i,x,y;
fin>>m;
for(i=1;i<=m;i++)
	{
	fin>>x>>y;
	fout<<cmmdc(x,y)<<'\n';
	}
fin.close();
fout.close();
}