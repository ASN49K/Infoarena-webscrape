#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,n;
int cmmdc(int a, int b)
{
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return cmmdc(b, a%b);
    }
}
int main()
{
    f>>n;
    for(int i=1; i<=n;i++)
       {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
       }

    return 0;
}
