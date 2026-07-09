#include<bits/stdc++.h>
using namespace std;
#define INIT  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define ll long long
#define pii pair<int, int>
#define count_bits __builtin_popcount
//#define int ll


ifstream fin("euclid2.in"); ofstream fout("euclid2.out");
#define cin fin
#define cout fout


int t, a, b;

int euclid(int a, int b){

if(b==0){
    return a;
}
return euclid(b, a%b);
}


int32_t main(){
INIT
cin>>t;
while(t--){
    cin>>a>>b;
    cout<<euclid(a, b)<<"\n";
}


return 0;
}
