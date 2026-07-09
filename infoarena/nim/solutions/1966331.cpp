#include<cstdio>
using namespace std;

int main()
{
    int t, n, x, sumXor, i, j;
    FILE *fin, *fout;
    fin = fopen("nim.in","r");
    fout = fopen("nim.out","w");
    fscanf(fin,"%d",&t);
    for(i=1; i<=t; i++)
    {
        sumXor = 0;
        fscanf(fin,"%d",&n);
        for(j=1; j<=n; j++)
        {
            fscanf(fin,"%d",&x);
            sumXor = sumXor ^ x;
        }
        if(sumXor > 0) fprintf(fout,"DA\n");
        else fprintf(fout,"NU\n");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
