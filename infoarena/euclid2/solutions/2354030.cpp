#include <cstdio>

using namespace std;

int cmmdc(int a,int b){
    int r;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,a,b;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}
