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
#include <limits.h>
#include <algorithm>
#include <deque>
#define inf 0x3f3f3f3f
#define mod 1000000007
#define nmax 100010
using namespace std;
int n,i,x,y;
int cmmdc(int x,int y)
{
    if (y==0) return x; else
        return (cmmdc(y,x%y));
}
int main() {
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&n);
for (i=1;i<=n;i++) {
    scanf("%d %d",&x,&y);
    printf("%d\n",cmmdc(x,y));
}

return 0;
}
