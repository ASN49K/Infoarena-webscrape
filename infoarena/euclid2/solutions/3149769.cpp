#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int cmmdc(int a, int b)
{
    int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int t,x,y;
    cin>>t;
    while(t>0)
    {
        cin>>x>>y;
        cout<<cmmdc(x,y)<<'\n';
        t--;
    }
    return 0;
}
