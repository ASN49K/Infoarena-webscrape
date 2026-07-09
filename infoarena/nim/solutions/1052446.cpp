#include <stdio.h>
#define fr(i,a,b) for(int i=a;i<b;++i)
int main(){
    int t;
    int n;
    long k;
    int j=0;
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%i",&t);
    fr(y,0,t){
        scanf("%d",&n);
        fr(i,0,n) scanf("%ld",&k),j^=k;
        printf(j?"DA\n":"NU\n");
        }
    return 0;
    }
