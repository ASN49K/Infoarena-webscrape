#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <limits.h>
#include <algorithm>
#include <deque>
using namespace std;
int t[1030][1030],n,m,i,j,k,v1[1030],v2[1030],sol[1030],nr=0;
inline int max(int a,int b) { if (a>b) return a; else return b; }
int main(){
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d %d",&n,&m);
for (i=1;i<=n;i++) scanf("%d",&v1[i]);
for (i=1;i<=m;i++) scanf("%d",&v2[i]);
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
        if (v1[i]==v2[j]) t[i][j]=t[i-1][j-1]+1; else
           t[i][j]=max(t[i-1][j],t[i][j-1]);
i=n; j=m;
while (t[i][j]>0) {
    while (t[i-1][j]==t[i][j]) i--;
    while (t[i][j-1]==t[i][j]) j--;
    nr++; sol[nr]=v1[i];
    i--; j--;
}
printf("%d\n",nr);
for (i=nr;i>=1;i--) printf("%d ",sol[i]);
return 0;
}
