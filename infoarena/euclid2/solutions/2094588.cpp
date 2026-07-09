#include <fstream>
using namespace std;
ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");
int cmmdc(int a, int b)
{
    if (!a&&!b)
        return 1;
    if (!a||!b)
        return a+b;
    int r;
    while (b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n,i,a,b;
    cin>>n;
    for (i=1;i<=n;++i)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
