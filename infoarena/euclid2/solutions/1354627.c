#include<stdio.h>
int main(){
    int a,b,n;
    
    freopen("euclid2.in","r",stdin);
    scanf("%d\n",&n);
    freopen("euclid2.out","w",stdout);
    while(--n>=0){
       scanf("%d %d",&a,&b);
       if(b>a){
             a+=b;b=a-b;a-=b;   
       }
       while((a%b!=0)){
             a=a%b;a+=b;b=a-b;a-=b;
       }
       printf("%d\n",b);               
    }
    return 0;
}
