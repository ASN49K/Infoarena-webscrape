using namespace std;
#include <fstream>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
void comp(unsigned int n,unsigned int a,unsigned int b);
int main()
{
unsigned int n,a,b;
fin>>n;
comp(n,a,b);
}
void comp(unsigned int n,unsigned int a,unsigned int b)
{
unsigned int i,r;
for(i=1;i<=n;i++)
{
	fin>>a>>b;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
		fout<<a<<"\n";
}
}
