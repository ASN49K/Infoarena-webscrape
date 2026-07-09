#include <fstream>

using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int a,i,n,b;

int cmmdc(int a, int b)
{
    int t;
    while(b!=0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
    f>>a>>b;
    g<<cmmdc(a,b)<<'/n';
    }
    return 0;
}
