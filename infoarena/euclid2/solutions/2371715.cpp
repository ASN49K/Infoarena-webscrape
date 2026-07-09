#include <bits/stdc++.h>
using namespace std;
void solve(int st,int dr,long long e){
    if (e==0) return;
    int n=dr-st+1;
    if(e<=1LL*(n-1)*(n-2)/2+1) {
        solve(st,dr-1,e-1);
        printf("%d %d\n",dr,st);
    }
    else{
        solve(st+1,dr,e-n+1);
        printf("%d %d\n",st+1,st);
    }
}
int main(){
    freopen("galeti2.in","r",stdin);
    freopen("galeti2.out","w",stdout);
    int n;
    long long e;
    scanf("%lld %lld",&n,&e);
    solve(1,n,e);
    return 0;
}
