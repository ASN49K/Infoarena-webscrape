//ssense
#include<bits/stdc++.h>
//#include "/Users/mihaiesanu/testlib.h"
#define startt ios_base::sync_with_stdio(false);cin.tie(0);
typedef unsigned long long ull;
typedef long long  ll;
using namespace std;
#define FOR(n) for(int i=0;i<n;i++)
#define vt vector
#define sz(a) (int)a.size()
#define MOD 1000000007
#define MOD2 998244353
#define MX 1000000000
#define NMAX 100005
#define MXL 1000000000000000000
#define PI 3.14159265
#define pb push_back
#define pf push_front
#define sc second
#define endl '\n'
#define fr first
#define int ll
#define ld long double
vector<int> primefac;
vector<int> d;
vector<int> adj[200030];
vector<int> dist;
bool nod[200030];
int ceildiv(int one, int two){
    if(one%two == 0)
    {
        return one/two;
    }
    else
    {
        return one/two+1;
    }
}void primeFactors(int n){
    primefac.clear();
    while (n % 2 == 0)
    {
        primefac.pb(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            primefac.pb(i);
            n = n/i;
        }
    }
    if (n > 2)
    {
        primefac.pb(n);
    }
}int power(int n, int pow, int m){
    if(pow == 0) return 1;
    if(pow%2 == 0){ll x = power(n, pow/2, m);
        return (x*x)%m;}
    else return (power(n, pow-1, m)*n)%m;
}
int gcd(int a, int b){
    if(!b)return a;
    return gcd(b,a%b);
}bool permutation(int arr[], int n){
    set<int> hash;
    int maxEle = 0;
    for (int i = 0; i < n; i++)
    {
        hash.insert(arr[i]);
        maxEle = max(maxEle, arr[i]);
    }
    if (maxEle != n)
    {
        return false;
    }
    if (hash.size()*1LL == n)
    {
        return true;
    }
    return false;
}void divis(int n){
    d.clear();
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            d.pb(i);
            if(i*i != n)
            {
                d.pb(n/i);
            }
        }
    }
    sort(d.begin(), d.end());
}int factorial(int n, int mod){
    if(n > 1)
        return (n*factorial(n - 1, mod))%mod;
    else
        return 1;
}int lcm(int a, int b){
    return (a*b)/gcd(a, b);
}bool checkPrimeNumber(int n){
    
    if (n <= 3)
    {
        return true;
    }
    
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    
    for (ll i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}string to_string(char c){return string(1, c);}string to_string(bool b){return b?"true":"false";}string to_string(const char* s){return string(s);}string to_string(string s){return s;}string to_string(vt<bool>v){string res;FOR(sz(v))res+=char('0'+v[i]);return res;}template<class T> string to_string(T v){bool f=1;string res;for(auto x:v){if(!f)res+=' ';f=0;res+=to_string(x);}return res;}template<class A> void write(A x){cout << to_string(x);}template<class H, class... T> void write(const H& h, const T&... t){write(h);write(t...);}void print(){write("\n");}template<class H, class... T> void print(const H& h, const T&... t) { write(h);if(sizeof...(t))write(' ');print(t...);}void dfs(int u){
    nod[u] = true;
    for(auto x : adj[u])
    {
        if(nod[x])continue;
        nod[x] = true;
        dfs(x);
    }
}void bfs(int s) {
    dist.assign(200005, -1);
    queue<int> q;
    dist[s] = 0; q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--)
    {
        int a,b;
        cin >> a >> b;
        cout << gcd(a,b) << endl;
    }
}

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

