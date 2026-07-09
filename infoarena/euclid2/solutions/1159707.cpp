#include <iostream>
#include <cstdio>
using namespace std;
int t,x,y,i;
int cmmdc(int x, int y)
{
    int r=1;
    while(r!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    FILE *fin=fopen("euclid2.in","r");
    FILE *fout=fopen("euclid2.out","w");
    fscanf(fin,"%d",&t);
    for(i=1;i<=t;i++)
    {
        fscanf(fin,"%d%d",&x,&y);
        fprintf(fout,"%d\n",cmmdc(x,y));
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
