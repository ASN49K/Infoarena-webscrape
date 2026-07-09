#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b;
int cmmdc(int a,int b)
{
    int r=0;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    f>>n;
    while(n--)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
