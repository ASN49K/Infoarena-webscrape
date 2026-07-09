#include <iostream>
#include <cstdio>

using namespace std;
long long n,t,x;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(size_t i = 1;i<=n;++i){
        cin >> t;
        int xr=0;
        while(t){
            cin >> x;
            xr^=x;
            --t;
        }
        if(xr)
            cout << "DA\n";
        else
            cout << "NU\n";
    }

    return 0;
}
