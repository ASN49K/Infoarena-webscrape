#include <cstdio>

using namespace std;

int t,x,y;

int cmmdc(int a,int b){
    if(b==0)return a;
    return cmmdc(b,a%b);
}

int main(){
    //freopen("date.in","r",stdin);
    //freopen("date.out","w",stdout);
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d ",&t);
    while(t--){
        scanf("%d %d ",&x,&y);
        printf("%d\n",cmmdc(x,y));
    }
    return 0;
}
