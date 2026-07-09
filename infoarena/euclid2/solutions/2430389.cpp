#include <bits/stdc++.h> //JuniorMonster a.k.a Sho10
#define ll long long
using namespace std;
int n,a,b;
int32_t main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
cin>>n;
for(ll i=0;i<n;i++)
{
    scanf("%d %d",&a,b);
        printf("%d\n", __gcd(a,b));
}
return 0;}
