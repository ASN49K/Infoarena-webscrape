#include <fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int t;

int cmmdc(int a,int b)
{
    int i,mini=min(a,b);
    for(i=mini;i>=1;i--)
        if(a%i==0 and b%i==0)
            return i;
}

int main()
{
    int i,a,b;
    in>>t;
    for(i=1;i<=t;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
