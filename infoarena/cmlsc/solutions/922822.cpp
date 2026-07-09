#include<stdio.h>
#include<algorithm>
using namespace std;
FILE *in,*out;
int n,m,i,j,raspuns[257];
int sir1[257], sir2[257],mat[257][257],u=-1;
int main()
{
    in=fopen("cmlsc.in","rt");
    out=fopen("cmlsc.out","wt");
    fscanf(in,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(in,"%d",&sir1[i]);
    for(i=1;i<=m;i++)
        fscanf(in,"%d",&sir2[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(sir1[i]==sir2[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;

            }
            else
                mat[i][j]=max(mat[i-1][j], mat[i][j-1]);
        }

    fprintf(out,"%d",mat[n][m]);
    fprintf(out,"\n");
    i=n;
    j=m;
    while(i && j)
    {
        if(sir1[i]==sir2[j])
        {
            raspuns[++u]=sir1[i];
            i--;
            j--;
        }
        else if(mat[i][j-1]>mat[i-1][j])
            j--;
        else
            i--;

    }
    for(i=u;i>=0;i--)
        fprintf(out,"%d ",raspuns[i]);


    fclose(in);
    fclose(out);
    return 0;
}
