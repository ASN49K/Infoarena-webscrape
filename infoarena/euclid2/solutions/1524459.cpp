#include <stdio.h>
using namespace std;
int n,x,y,i;
int gcd(int a,int b)
{
    if (b==0) return a; else
        return gcd(b,a%b);
}
int main() {
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&n);
for (i=1;i<=n;i++) {
    scanf("%d %d",&x,&y); printf("%d\n",gcd(x,y));
}
return 0;
}
