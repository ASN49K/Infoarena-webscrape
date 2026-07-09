#include <bits/stdc++.h>

using namespace  std;
const int nmax = 1001;
const int MOD = 1e9+7;

int gcd(int a,int b){
    int r;
    while(b) r=a%b,a=b,b=r;
    return a;
}
int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,a,b;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        cout<<gcd(a,b)<<'\n';
    }
}