#include <cstdio>

int main()
{
    FILE *fin,*fout;
    fin=fopen("nim.in","r");
    fout=fopen("nim.out","w");
    int t,n,x,s;
    fscanf(fin,"%d",&t);
    for(int i=0;i<t;i++)
    {
        fscanf(fin,"%d",&n);
        s=0;
        for(int j=0;j<n;j++)
        {
            fscanf(fin,"%d",&x);
            s^=x;
        }
        if(s)
            fprintf(fout,"DA\n");
        else
            fprintf(fout,"NU\n");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
