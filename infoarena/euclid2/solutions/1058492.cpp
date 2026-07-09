#include<cstdio>
FILE *fi=fopen("euclid2.in","rt");
FILE *fo=fopen("euclid2.out","wt");
int  cmmdc(int x,int y)
{
    int c;
    while(x>1&&y>1)
    {
        c=x%y;
        if(c==0) return y;
        x=y;
        y=c;
    }
    return 1;
}
int main()
{
    int n,x,y;
    fscanf(fi,"%ld",&n);
    for(int i=1;i<=n;i++)
    {
        fscanf(fi,"%ld%ld",&x,&y);
        fprintf(fo,"%ld\n",cmmdc(x,y));
    }
}
