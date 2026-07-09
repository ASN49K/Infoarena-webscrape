#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int a,b,t,i;

int cmmdc(int a, int b)
{
    int r;
    r=a%b;
    while(r>0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    cin>>t;
    for(i=1;i<=t;++i)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
