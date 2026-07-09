#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int te;
    cin>>te;
    while(te--)
    {
        int tot=0;
        int n,grundy;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>grundy;
            tot^=grundy;
        }
        if(tot!=0) cout<<"DA\n"; else cout<<"NU\n";
    }
    return 0;
}
