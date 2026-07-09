#include <fstream>

using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int cmmdc(int a,int b)
{
    if(!b)
        return a;
    else
        return cmmdc(b,a%b);
}

int main()
{
    int a,i,n,b;
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
