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
#define mod 1000000007
#define PI 3.14159265359
#define CODE_START  ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
using namespace std;
ll n,m,a[2000],b[2000],s[2000][2000];
vector<ll>ans;
int32_t main(){
CODE_START;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
cin>>m>>n;
for(ll i=1;i<=m;i++)
cin>>a[i];
for(ll i=1;i<=n;i++)
cin>>b[i];
for(ll i=1;i<=m;i++)
{
for(ll j=1;j<=n;j++)
if(a[i]==b[j]){
s[i][j]=s[i-1][j-1]+1;
}else s[i][j]=max(s[i-1][j],s[i][j-1]);
}
   ll g=m,h=n,k=s[m][n],i=m,j=n;
    while(k){
        if(a[i]==b[j]){
            ans.pb(a[i]);
            i--;
            j--;
            k--;
        }
        else{
            if(s[i][j-1]>=s[i-1][j]) j--;
            else i--;
        }
    }
   cout<<s[m][n]<<endl;
    for(ll i=s[m][n]-1;i>=0;i--){
        cout<<ans[i]<<' ';
    }

}


