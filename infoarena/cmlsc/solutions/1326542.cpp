#include <fstream>
#define NMAX 1030

using namespace std;

FILE* f=freopen("cmlsc.in","r",stdin);
FILE* o=freopen("cmlsc.out","w",stdout);

int n,m;

int a[NMAX],b[NMAX],sir[NMAX];
int d[NMAX][NMAX];

int maxim(int a, int b) { return (a<b)?b:a; }

void PD()
{
    int i=1,j=1;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&b[i]);
    }

    PD();

    int num=0;

    for(int i=n,j=m;i;)
    {
        if(a[i]==b[j]) sir[num++]=a[i],i--,j--;
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
    }

    printf("%d\n",num);

    for(num-=1;num>=0;num--)
        printf("%d ",sir[num]);

    return 0;
}
