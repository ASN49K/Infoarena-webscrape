#include<cstdio>
#include<algorithm>
using namespace std;

FILE *in,*out;

short int  n,m,answer[1025];
short int v1[1025], v2[1025];
short int a[1025][1025],u=-1;
int main()
{
    in=fopen("cmlsc.in","rt");

    fscanf(in,"%hd%hd",&n,&m);

    for(short int i=1;i<=n;i++)
        fscanf(in,"%hd",&v1[i]);

    for(short int i=1;i<=m;i++)
        fscanf(in,"%hd",&v2[i]);

    fclose(in);

    for(short int i=1;i<=n;i++)
        for(short int j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                a[i][j]=a[i-1][j-1]+1;

            }
            else
                a[i][j]=max(a[i-1][j], a[i][j-1]);
        }

    out=fopen("cmlsc.out","wt");

    fprintf(out,"%hd",a[n][m]);
    fprintf(out,"\n");

    short int i=n;
    short int j=m;

    while(i && j)
    {
        if(v1[i]==v2[j])
        {
            answer[++u]=v1[i];
            i--;
            j--;
        }
        else if(a[i][j-1]>a[i-1][j])
            j--;
        else
            i--;

    }

    for(short int i=u;i>=0;i--)
        fprintf(out,"%hd ", answer[i]);

    fclose(out);
    return 0;
}
