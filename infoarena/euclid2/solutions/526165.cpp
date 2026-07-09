#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long x[100010],T,i,a,b,r,j,cmmdc;
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
        for(j=0;j<T;j++)
		{
		g<<cmmdc<<'\n';
		break;
		}
		}
		return 0;
    }