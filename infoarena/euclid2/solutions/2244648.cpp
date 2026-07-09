#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int t,a,b;
int cmmdc(int x,int y);
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
int cmmdc(int x,int y)
{
    int r=x%y;
    while(r)
    {
        x=y;y=r;r=x%y;
    }
    return y;
}
