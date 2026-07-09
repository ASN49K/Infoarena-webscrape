#include <fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");
int cmmdc(int a,int b)
{
    while (a!=b)
    {
        if (a>b)a-=b;
        else b-=a;
    }
    return a;
}
int main ()
{
    int n,a,b,i;
    in>>n;

    for (i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<endl;

    }

return 0;}
