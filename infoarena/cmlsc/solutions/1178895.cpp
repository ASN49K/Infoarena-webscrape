#include <cstdio>
#define nrmax 1030

using namespace std;

int n,m,a[nrmax],b[nrmax],mat[nrmax][nrmax],rasp[nrmax],nr;
void afis(FILE *fis)
{
    int i, j;
    for(i=0; i<=n; i++){
        for(j=0; j<=m; j++)
            fprintf(fis, "%3d ", mat[i][j]);
        fprintf(fis, "\n");
    }
    fprintf(fis, "\n");
}
int main()
{
    FILE*f=fopen("cmlsc.in","r");
    FILE*g=fopen("cmlsc.out","w");
    int i,j;
    fscanf(f,"%d%d",&n,&m);
    for(i=1;i<=n;++i)
        fscanf(f,"%d",a+i);
    for(i=1;i<=m;++i)
        fscanf(f,"%d",b+i);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                if(mat[i-1][j]>mat[i][j-1])
                    mat[i][j]=mat[i-1][j];
                else
                    mat[i][j]=mat[i][j-1];
    i=n,j=m;
    //afis(g);
    fprintf(g,"%d\n",mat[i][j]);
    while(i>0 and j>0)
        if(a[i]!=b[j])
            if(mat[i-1][j]>mat[i][j-1])
                i--;
            else
                j--;
        else
        {
            nr++;
            rasp[nr]=a[i];
            i--;
            j--;

        }
    for(i=nr;i>=1;--i)
        fprintf(g,"%d ",rasp[i]);
    fclose(f);
    fclose(g);
    return 0;
}
