#include <cstdio>

#define max(a,b) ((a>b)?a:b)

using namespace std;

int n,m,a[1030],b[1030],v[1030][1030];

int main()
{
    FILE *f=fopen("cmlsc.in","r");
    fscanf(f,"%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&a[i]);
    for(i=1;i<=m;i++)
        fscanf(f,"%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    int lenght=0,allah[1030];
    i=n;j=m;
    while(a[i]||b[j])
    {
        if(a[i]==b[j])
        {
            allah[++lenght]=a[i];
            i--;
            j--;
        }
        else if(v[i-1][j]<v[i][j-1]) j--;
        else i--;
    }
    fclose(f);
    f=fopen("cmlsc.out","w");
    fprintf(f,"%d\n",lenght);
    for(i=lenght;i>=1;i--)
        fprintf(f,"%d ",allah[i]);
    return 0;
}
