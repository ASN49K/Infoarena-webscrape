#include <cstdio>

using namespace std;

int euclid(int a,int b){
    int r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,a,b;
    scanf("%d",&n);
    for(n;n;n--){
        scanf("%d%d",&a,&b);
        int c=euclid(a,b);
        printf("%d\n",c);
    }
    return 0;
}
