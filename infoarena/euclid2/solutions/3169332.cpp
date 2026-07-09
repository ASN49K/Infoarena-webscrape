#include <fstream>


using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");


void solve()
{
    int a,b,r;
    cin>>a>>b;
    while(b!=0)
   {
        r=a%b;
        a=b;
        b=r;
    }

    cout<<a<<"\n";
}


int main()
{
    int t;
    cin>>t;

    while(t--)
        solve();
    return 0;
}
