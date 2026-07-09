#include <stdio.h>
using namespace std;
int n,i,j,sol,x,m;
int main() {
freopen("nim.in","r",stdin);
freopen("nim.out","w",stdout);
scanf("%d",&n);
for (i=1;i<=n;i++) {
    scanf("%d",&m); sol=0;
    for (j=1;j<=m;j++) { scanf("%d",&x); sol=sol^x; }
    if (sol==0) puts("NU"); else puts("DA");
}
return 0;
}
