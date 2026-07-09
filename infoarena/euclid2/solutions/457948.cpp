#include<fstream>
using namespace std;
int a,b,n,i;
int cmmdc(int a, int b)
{
	if(!b)
		return a;
	return cmmdc(b,a%b);
}
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<"\n";
	}
	return 0;
}
