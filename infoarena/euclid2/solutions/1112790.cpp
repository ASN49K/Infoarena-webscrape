#include<cstdio>
using namespace std;
int n,a,b;
void euclid(int a, int b){
    int r;
    r=a%b;
    while(r){
            a=b;
            b=r;
            r=a%b;
    }
    printf("%d\n",b);
}
int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
            scanf("%d%d",&a,&b);
            euclid(a,b);
    }
    return 0;
}
