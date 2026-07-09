#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int cmmdc(int a, int b)
{
    int r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    int a,b,i,n;
    cin>>n;
    for(i=1;i<=n;i++)
    {
    cin>>a>>b;
    cout<<cmmdc(a,b)<<'\n';
    }
}

