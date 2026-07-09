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

inline void START(string online_judge) {
    if(online_judge=="infoarena" || online_judge=="varena") {
        OpenALL();
    }
    if(online_judge=="codeforces") {
        ios_base::sync_with_stdio(0);
        cin.tie(0), cout.tie(0);
    }
}

int main() {
    START("infoarena");
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++) {
        int a,b;
        cin>>a>>b;
        cout<<__gcd(a,b)<<"\n";
    }
    return 0;
}
