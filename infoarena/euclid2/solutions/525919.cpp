#include<fstream>
using namespace std;
ifstream f("euclid2in");
ofstream g("euclid2.out");
long long cmmdc,a,b,r,i,T;
int main()
	{
		f>>T;
		for(i=1;i<=T;i++)
		{
		f>>a;
		f>>b;
		while(b!=0)
		{
			r=a%b;
			a=b;
			b=r;
		}
        cmmdc=a;		
		g<<cmmdc<<'\n';
		}
		return 0;
    }