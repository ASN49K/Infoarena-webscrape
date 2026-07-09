#include <cstdio>
#define max(a,b) ((a > b) ? a : b)

using namespace std;

int m,n,a[1025],b[1025];
int c[1025][1025];

void citire()
{
    scanf("%d%d",&M,&N);
    for(int i=0; i<m; i++)
        scanf("%d",&a[i]);

    for(int i=1;i<n;i++)
        scanf("%d",&b[i]);
}

void cauta()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
}

void drum(int i, int j)
{
    if(c[i][j]==0)
        return;
    if(a[i]==b[j])
    {
        drum(i-1,j-1);
        printf("%d ",a[i]);
        return;
    }
    if(c[i-1][j]>c[i][j-1])
    {
        drum(i-1,j);
        return;
    }
    drum(i,j-1);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    cauta();
    printf("%d\n",c[m][n]);
    drum(m,n);
    return 0;
}
