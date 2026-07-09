#include<fstream>
using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
int a,b,r;
int main()
{
	f>>a>>b;
	while(b!=0)
	    {r=a%b;
		 a=b;
		 b=r;
		}
	g<<a;
	g.close();
	return 0;
}	

	
