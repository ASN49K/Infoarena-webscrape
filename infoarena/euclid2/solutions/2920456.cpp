#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define ar array
#define ln '\n'
#define cin f
#define cout g
#define pb push_back
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t;
void solve(){
int a,b;cin>>a>>b;
while(b){
    int r=a%b;
    a=b;
    b=r;
}
cout<<a<<ln;
}
int main(){
    cin>>t;
    while(t--)solve();
}
/// (n^2-1)/4
