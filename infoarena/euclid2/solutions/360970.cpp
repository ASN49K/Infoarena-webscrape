#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
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
