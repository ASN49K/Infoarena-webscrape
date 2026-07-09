#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <iterator>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define maxi(a,b) ((a>b)? a : b)
#define FOR(i,x,n) \
for(int i = int(x);i <= int(n);i++)

int n,m,v[1025],w[1025],d[1025][1025],rez[1025],x;
int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d", &n, &m);
    FOR(i,1,n)scanf("%d", &v[i]);
    FOR(i,1,m)scanf("%d", &w[i]);

    FOR(i,1,n)
    FOR(j,1,m)if(v[i]==w[j])d[i][j]= 1 + d[i-1][j-1];
                else d[i][j] = maxi(d[i-1][j],d[i][j-1]);

    while(n)if(v[n]==w[m])rez[++x]=v[n],--n,--m;
            else if(d[n-1][m]<d[n][m-1])m--;
                 else n--;
    printf("%d\n",x);
    while(x)printf("%d ",rez[x--]);
return 0;
}
