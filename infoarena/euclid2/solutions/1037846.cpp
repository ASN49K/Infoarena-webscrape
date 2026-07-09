#include <fstream>
using namespace std;
fstream f("euclid2.in");
ofstream g("euclid2.out");

int main() {
	int T,a,b,r;
	f>>T;
	for(int i=1;i<=T;++i)
	{
	f>>a>>b;
		while(a!=0)
		{
			r=a%b;
			a=b;
		    b=r;
		}
	g<<b;
	}


	return 0;
	}
