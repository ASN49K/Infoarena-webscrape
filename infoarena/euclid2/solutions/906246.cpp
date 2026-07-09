#include <cstdio>
int cmmdc(int a,int b){
    if(b==0){
        return a;
    }
    cmmdc(b,a%b);
}
int main () {
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,i,a,b,c;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d %d",&a,&b);
        if(a<b){
            c=b;
            b=a;
            a=c;
        }
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}
