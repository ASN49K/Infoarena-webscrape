#include<stdlib.h>
#include<stdio.h>

int cmmdc(int a, int b)
{
    return a==b ? a : a>b? cmmdc(a-b,b) : cmmdc(a,b-a);
}

int main(){
    
    FILE *f = NULL;
    FILE *o = NULL;
    int n;
    int i =0;
    int a, b;
    
    f = fopen("/Users/dan/Documents/Probleme/infoarena/euclid2.in","r");
    if(!f) return -1;
    
    o = fopen("/Users/dan/Documents/Probleme/infoarena/euclid2.out","w+");
    if(!o) return -1;
    
    fscanf(f,"%d",&n);
    while(i < n)
    {
        fscanf(f,"%d %d",&a,&b);
        printf("%d \n",cmmdc(a,b));
        i++;
        fprintf(o,"%d\n",cmmdc(a,b));
    }
    
   
    return 0;
}
