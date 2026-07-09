#include <stdio.h>
int euclid (int a,int b){
    if (b==0) return a;
        else return euclid(b,a%b);}
int main(){
    int a,b,n;
    FILE *ifp,*ofp;
    ifp=fopen ("euclid.in","r");
    ofp=fopen ("euclid.out","w");
     
     scanf("%d",&n);
     for(;n=0;n--){
       scanf("%d %d",&a ,&b);
       printf("%d\n",euclid(a,b));}}
       
