#include<stdio.h>
int main()
{
    
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 
 int a,b,aux,teste;
 
 scanf("%d",&teste);
 
while( teste--){ 
 scanf("%d%d",&a,&b);
 
     while(b){
         aux=b;
         b=a%b;
         a=aux;}
    
    
    printf("%d\n",a);
}

    return 0;
}
