#include <fstream>

using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
int a,b,t,i;
int cmmdc(int a, int b)
{int r;
if(!b) return a;
     while(b)
        {
        r=a%b;
        a=b;
        b=r;

        }
return a;}

int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {f>>a>>b; g<<cmmdc(a,b)<<'\n';}

    f.close();g.close();
    return 0;
}
