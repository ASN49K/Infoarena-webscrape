#include <cstdio>
#define nrmax 1030

using namespace std;

int n,m,a[nrmax],b[nrmax],mat[nrmax][nrmax],rasp[nrmax],nr;
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
    for(i=2;i<=n+1;++i)
        for(j=2;j<=m+1;++j)
            if(a[i-1]==b[j-1])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                if(mat[i-1][j]>mat[i][j-1])
                    mat[i][j]=mat[i-1][j];
                else
                    mat[i][j]=mat[i][j-1];
    i=n+1,j=m+1;
    fprintf(g,"%d\n",mat[i][j]);
    while(i>2 or j>2)
        if(a[i-1]!=b[j-1])
            if(mat[i-1][j]>mat[i][j-1])
                i--;
            else
                j--;
        else
        {
            i--;
            j--;
            nr++;
            rasp[nr]=a[i];
        }
    for(i=nr;i>=1;--i)
        fprintf(g,"%d ",rasp[i]);
    fclose(f);
    fclose(g);
    return 0;
}
