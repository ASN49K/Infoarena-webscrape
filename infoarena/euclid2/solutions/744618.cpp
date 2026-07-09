#include <cstdio>

int cmmdc(int x,int y){
    if(y==0) return x; else
        return cmmdc(y,x%y);
}

int main(){
    int x,y,t;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&x,&y);
        printf("%d\n",cmmdc(x,y));
    }
}
