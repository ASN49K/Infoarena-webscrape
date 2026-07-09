#include <fstream>
using namespace std;
ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");
int CMMDC(int a, int b)
{
    if (b==0)
        return a;
    return CMMDC(b, a % b);
}
int main()
{
    int i,t,a,b;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>a>>b;
        cout<<CMMDC(a,b)<<'\n';
    }
    return 0;
}
