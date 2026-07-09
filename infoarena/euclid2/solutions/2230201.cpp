#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b,cmmdc(int,int);
int main()
{
    f>>n;
    for(; n; n--)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }

    return 0;
}
int cmmdc(int a,int b)
{

    if(b==0)return a;
    return cmmdc(b,a%b);
}
