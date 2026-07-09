#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{
	int r=a%b;
   while(r)
    {
        
        a=b;
        b=r;
	r=a%b;
    }
    return b;

}
int main()
{
int t,i,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a;
	f>>b;
        g<<cmmdc(a,b);
	g<<'\n';
    }
    f.close();
    g.close();
    return 0;
}