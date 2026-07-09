#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,r;
int main()
{
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>a>>b;
        r=0;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';
    }
	g.close();
	return 0;
}
