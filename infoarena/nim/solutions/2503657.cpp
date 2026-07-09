#include <bits/stdc++.h> //JuniorMonster a.k.a Sho10
#define ll long long int
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define all(a) (a).begin(), (a).end()
#define sz size
#define f first
#define s second
#define pb push_back
#define er erase
#define in insert
#define mp make_pair
#define pi pair
#define rc(s) return cout<<s,0
#define endl '\n'
#define mod 1000000007
#define PI 3.14159265359
#define CODE_START  ios_base::sync_with_stdio();cin.tie();cout.tie();
using namespace std;
ll t,n,x,ans=0;
int32_t main(){
CODE_START;
ifstream cin("nim.in");
ofstream cout("nim.out");
cin>>t;
while(t--){
    cin>>n;
    ans=0;
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        ans=(ans^x);
    }
    if(ans!=0){
        cout<<"DA"<<endl;
    }else cout<<"NU"<<endl;
}
}





