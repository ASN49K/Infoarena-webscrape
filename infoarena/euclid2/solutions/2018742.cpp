#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const lli mod=1e9+7;
const lli pINF=LLONG_MAX;
const lli nINF=-LLONG_MAX;
void fast() {std::ios::sync_with_stdio(false);cin.tie(NULL);}
lli power(lli a,lli b){lli ans=1;while(b!=0){ if(b%2==1){ans*=a;}b/=2;a*=a;} return ans;}
lli invmod(lli a) {return pow(a,mod-2);}
#define vi vector<int>
#define vlli vector<lli>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sli(n) scanf("%lld",&n)
#define printi(n) printf("%d\n",n)
#define printli(n) printf("%lld\n",n)
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
void print(int a[],int n){for(int i=0;i<n;i++) cout<<a[i]<<" ";}

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int t,x,y;
    fin>>t;

    while(t--){
        fin>>x>>y;
        int ans=gcd(x,y);
        fout<<ans<<endl;
    }
    return 0;
}
