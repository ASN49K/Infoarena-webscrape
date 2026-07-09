#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long a,b,c,n;
int main()
{
f>>n;
for(int i=1;i<=n;++i)
	{
	f>>a>>b;
	while(b)
		{
		c=a%b;
		a=b;
		b=c;
		}
	g<<a<<'\n';
	}
return 0;
}
