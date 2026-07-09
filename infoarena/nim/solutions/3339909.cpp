#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

void solve()
{
    int x=0,n,a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        x^=a;
    }
    cout<<((x==0)? "NU\n" : "DA\n");
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
