#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t,n,rez,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        while(n--)
        {
            cin>>a;
            rez^=a;
        }
        if(rez==0)cout<<"NU\n";
        else cout<<"DA\n";
    }
	return 0;
}
