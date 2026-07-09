#include <cstdio>
#define nmax 1100

using namespace std;

int m[nmax][nmax],n,p,a[nmax],b[nmax],st[nmax],vf;

void citire()
{
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=p;i++)
        scanf("%d",&b[i]);
}

int maxim(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

void rezolv()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=p;j++)
        {
            if(a[i]==b[j])
                m[i][j]=m[i-1][j-1]+1;
            else
                m[i][j]=maxim(m[i-1][j],m[i][j-1]);
        }
}

void reconstruct()
{
    int i=n,j=p;
    while(m[i][j])
    {
        if(a[i]==b[j])
        {
            st[++vf]=a[i];
            i--;
            j--;
        }
        else
        if(m[i][j]==m[i-1][j])
            i--;
        else
            j--;
    }
}

void afisare()
{
    printf("%d\n",m[n][p]);
    for(int i=vf;i>=1;i--)
        printf("%d ",st[i]);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    rezolv();
    reconstruct();
    afisare();
    return 0;
}
