#include<fstream>
using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
int n,a,b;
int cmmdc(int a,int b)
{
	if(!b)
		return a;
	else return cmmdc(b,a%b);
}
int main()
{
	f>>n;
	
	while(n--)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<'\n';
	}
	return 0;
}