#include<stdlib.h>
#include<stdio.h>

int cmmdc(int a, int b)
{
    if(a == 0)
        return a;
    else
        return euclid_gcd_recur(b, a % b);}

int main(){
    
    FILE *f = NULL;
    FILE *o = NULL;
    int n;
    int i =0;
    int a, b;
    
    f = fopen("euclid2.in","r");
    if(!f) return -1;

    o = fopen("euclid2.out","w+");
    if(!o) return -1;
    
    fscanf(f,"%d",&n);
    while(i < n)
    {
        fscanf(f,"%d %d",&a,&b);
//        printf("%d \n",cmmdc(a,b));
        i++;
        fprintf(o,"%d\n",cmmdc(a,b));
    }
    
   
    return 0;
}
