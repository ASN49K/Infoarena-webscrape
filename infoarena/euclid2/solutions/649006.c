#include <stdio.h>
int euclid (int a,int b){
    if (b==0) return a;
        else return euclid(b,a%b);}
int main(){
    int a,b,n;
    FILE *ifp,*ofp;
    ifp=freopen ("euclid.in","r",stdin);
    ofp=freopen ("euclid.out","w",stdout);
     
     scanf("%d",&n);
     for(;n=0;n--){
       scanf("%d %d",&a ,&b);
       printf("%d\n",euclid(a,b));}
       return 0;}
       
