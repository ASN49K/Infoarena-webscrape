#include <bits/stdc++.h>       // Grandmixer //
#define ll long long
#define sz size
#define pb push_back
#define er erase
#define in insert
#define fr first
#define sc second
#define mp make_pair
#define pi pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
#define rc(s) return cout<<s,0
const int mod=1e9+7;
const int inf=1e5;
using namespace std;

long long a,b;
long long gcd(long long  a, long long b){
    if (b==0) return a;
    return gcd(b,a%b);
}

int main(){
    cin >> a >> b;
    cout<<gcd(a,b);
}
