#include <stdio.h>
#define fr(i,a,b) for(int i=a;i<b;++i)
int main(){
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int t,n,j,k;
    scanf("%i",&t);
    fr(y,0,t){
        scanf("%i",&n);
        j=0;
        fr(i,0,n)scanf("%i",&k),j^=k;
        printf(j?"DA\n":"NU\n");
        }
    return 0;
    }
