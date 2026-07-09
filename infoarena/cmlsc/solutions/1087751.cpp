#include<fstream>
#define NMAX 1030

using namespace std;

FILE* f=freopen("cmlsc.in","r",stdin);
FILE* o=freopen("cmlsc.out","w",stdout);

int n,m;
int a[NMAX],b[NMAX],mat[NMAX][NMAX],rez[NMAX];

int maxim(int a, int b)
{
    return ((a>b)?a:b);
}

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<m;++i)
        scanf("%d",&b[i]);

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=maxim(mat[i-1][j],mat[i][j-1]);

    int ind=0;
    for(int i=n;i>=1;)
        for(int j=m;j>=1;)
            if(a[i]==b[j])
            {
                rez[ind++]=a[i];
                --j;--i;
            }
            else if(mat[i][j-1]>mat[i-1][j])
                j-=1;
            else
                i-=1;
    printf("%d\n",ind);
    for(ind-=1;ind>=0;--ind) printf("%d ",rez[ind]);

	return 0;
}
