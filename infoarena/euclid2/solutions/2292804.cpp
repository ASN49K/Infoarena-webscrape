#include<bits/stdc++.h>
using namespace std;
//Subprograme
bool vocala(char c){
 if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')
    return true;
  if(c=='Y'||c=='y')return true;
 return false;
}
int isprime(long long n){
if(n==1)return 0;
if(n==2)return 1;
if(n%2==0)return 0;
for(int i=3;i*i<=n;i+=2)
    if(n%i==0)return 0;
return 1;
}
int isfibo(long long n){
long long a=5*n*n+4;
long long b=a-8;
if(sqrt(a)==int(sqrt(a))|| sqrt(b)==int(sqrt(b)))
    return 1;
return 0;
}
int gcd(long long a,long long b){
long long r;
while(b){
    r=a%b;
    a=b;
    b=r;
}
return a;
}
//End subprograme
ifstream in("euclid2.in");
ofstream out("euclid2.out");
#define opt1 ios_base::sync_with_stdio(0)
#define MOD 1000000007
#define lb lower_bound
#define up upper_bound
#define er equal_range
#define opt2 cin.tie(0)
#define opt3 cout.tie(0)
#define fi first
#define se second
#define save1 in.close()
#define save2 out.close()
#define mp make_pair
#define pb push_back
#define bs bitset
#define bpc __builtin_popcount
long long const nrmax=1e18;
typedef long long ll;
typedef unsigned long long int ull;
typedef vector<ull> vull;
typedef vector<vector<ull>> vvull;
typedef vector<pair<int,ull>> vpiull;
typedef vector<pair<ull,int>> vpulli;
typedef vector<pair<ll,ull>> vpllull;
typedef vector<pair<ull,ll>> vpullll;
typedef vector<pair<ull,ull>> vpullull;
typedef pair<ull,ull> pullull;
typedef string str;
typedef char chr;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<int>> vvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef pair<ll,int> plli;
typedef pair<ll,ll> pllll;
typedef vector<pii> vpii;
typedef vector<vector<pii>> vvpii;
typedef vector<pill> vpill;
typedef vector<vector<pill>> vvpill;
typedef vector<plli> vplli;
typedef vector<vector<plli>> vvplli;
typedef vector<pllll> vpllll;
typedef vector<vector<pllll>> vvpllll;
typedef map<int,int> mii;
typedef map<int,ll> mill;
typedef map<ll,int> mlli;
typedef map<ll,ll> mllll;
typedef map<ll,chr> mllc;
typedef map<chr,int> mci;
typedef map<ll,str> mlls;
typedef map<str,int> msi;
typedef map<str,ll>msll;
typedef map<chr,ll>mcll;
/*Hard work beats talent,Please Work Hard,Alex.You will get there one day,I
promise you!! <3 <3.I love you, bro!Very Much!*/

int main()
{opt1;opt2;opt3;

   ll n;in>>n;
   for(int i=1;i<=n;++i){
     ll a,b;in>>a>>b;
     out<<gcd(a,b)<<'\n';
   }


#ifdef LOCAL_DEFINE;
        cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
    #endif
save1;save2;
//http://m1.codeforces.com/enter
return 0;
}
