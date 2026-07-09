#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,n;
int cmmdc(int a,int b)
{
    while(b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
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
