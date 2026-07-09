#include <stdio.h>
struct prob{
    int x,y;
    void get(){ scanf("%d %d",&x,&y); }
    int gcd(int a,int b){
        if(!b)return a;
        return gcd(b,a%b); }
    void pair(){ get(); printf("%d\n",gcd(x,y)); }
}get;

int main(){
    int n;
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&n);
    for(;n>0;n--)get.pair();
}
