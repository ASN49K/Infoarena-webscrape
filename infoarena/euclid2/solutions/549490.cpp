using namespace std;
#include <fstream>
int main()
{
unsigned int n,i;
unsigned long int a,b;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
for(i=1;i<=n;i++)
{
	fin>>a>>b;
	while(a!=b)
	{
	if(a<b)
		b=b-a;
	if(a>b)
		a=a-b;
	}
		fout<<a<<"\n";
}
}
