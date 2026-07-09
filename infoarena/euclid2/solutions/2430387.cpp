
#include <bits/stdc++.h> //JuniorMonster a.k.a Sho10
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define all(a) (a).begin(), (a).end()
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define sz size
#define f first
#define s second
#define pb push_back
#define er erase
#define in insert
#define mp make_pair
#define pi pair
#define rc(s) return cout<<s,0
#define mod 1000000007
#define PI 3.14159265359
#define CODE_START  ios_base::sync_with_stdio();cin.tie();cout.tie();
using namespace std;
ll n,a,b;
int32_t main(){
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
CODE_START;
cin>>n;
for(ll i=0;i<n;i++)
{
    cin>>a>>b;
    cout<<__gcd(a,b)<<endl;
}
return 0;}
