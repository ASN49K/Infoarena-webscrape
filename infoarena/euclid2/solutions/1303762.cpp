#include <stdio.h>
int cmmdc(int a,int b)
{
    if(a%b==0) return b;
    if(b%a==0) return a;
    return cmmdc(a%b,b%a);
}
int t;
int main()
{
    FILE *fin,*fout;
    fin=fopen("euclid2.in","r");
    fout=fopen("euclid2.out","w");
    fscanf(fin,"%d",&t);
    int a,b;
    for(int i=1;i<=t;i++)
    {
        fscanf(fin,"%d%d",&a,&b);
        fprintf(fout,"%d\n",cmmdc(a,b));
    }
}
