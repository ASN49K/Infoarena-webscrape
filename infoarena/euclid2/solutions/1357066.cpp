#include<stdio.h>

int cmmdc(int a,int b)
{
    if(a%b==0)
    {
              return b;
    }
    return cmmdc(b,a%b);
}

int main()
{
    FILE *fin,*fout;
    fin=fopen("euclid2.in","r");
    fout=fopen("euclid2.out","w");
    
    int n,t1,t2;
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
            fscanf(fin,"%d %d",&t1,&t2);
            fprintf(fout,"%d\n",cmmdc(t1,t2));
    }
}
