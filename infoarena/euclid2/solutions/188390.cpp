#include<stdio.h>
int n,a1,b1;
int Euclid(int a, int b){
    int r;
    do{
        r=a%b;
        a=b;
        b=r;}
    while(r);
    return a;}
void Rezolvare(){
     int i;
     scanf("%d",&n);
     for(i=1; i<=n; ++i){
              scanf("%d%d",&a1,&b1);
              printf("%d\n",Euclid(a1,b1));}}
int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    Rezolvare();
    return 0;}
