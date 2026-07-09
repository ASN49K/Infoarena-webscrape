#include<stdio.h>

int main()
{
    FILE *fin,*fout;
    fin=fopen("nim.in","r");
    fout=fopen("nim.out","w");
    int n,m,sum,temp;
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        sum=0;
        fscanf(fin,"%d",&m);
        for(int j=0;j<m;j++)
        {
            fscanf(fin,"%d",&temp);
            sum=sum xor temp;
        }
        if(sum==0)  fprintf(fout,"NU\n");
        else    fprintf(fout,"DA\n");
    }
}
