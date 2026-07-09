#include <stdio.h>
inline int cmmdc(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    FILE *fin,*fout;
    fin=fopen("euclid2.in","r");
    fout=fopen("euclid2.out","w");
    int t,i,a,b;
    fscanf(fin,"%d",&t);
    for(i=0;i<t;i++)
    {
        fscanf(fin,"%d%d",&a,&b);
        fprintf(fout,"%d\n",cmmdc(a,b));
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
