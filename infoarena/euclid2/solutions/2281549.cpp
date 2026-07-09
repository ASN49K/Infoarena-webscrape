#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const string FILENAME="euclid2";

#define OpenIN() freopen((FILENAME+".in").c_str(),"r",stdin)
#define OpenOUT() freopen((FILENAME+".out").c_str(),"w",stdout)
#define OpenALL() OpenIN(), OpenOUT()
#define infoarena() OpenALL()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    infoarena();
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<__gcd(a,b)<<"\n";
    }
    return 0;
}
/**



**/
