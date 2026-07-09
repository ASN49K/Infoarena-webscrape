#include <iostream>

using namespace std;

short int m[1025][1025];
char sir1[1025],sir2[1025];
short int n1,n2;

int max(int x,int y)
{
    return x<y?y:x;
}

int main()
{
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    scanf("%d %d",&n1,&n2);
    for(int i=1;i<=n1;i++)
        scanf("%d",&sir1[i]);
    for(int i=1;i<=n2;i++)
        scanf("%d",&sir2[i]);

    for(int i=1;i<=n1;i++)
        for(int j=1;j<=n2;j++)
            if(sir1[i]==sir2[j])
                m[i][j]=m[i-1][j-1]+1;
            else m[i][j]=max(m[i-1][j],m[i][j-1]);

    int i=n1,j=n2;
    int g=m[i][j];
    cout<<g<<endl;
    while(g>0)
    {
        if(m[i-1][j-1]==g-1)sir2[g--]=sir1[i];
            else if(m[i-1][j]==g) i--;
                    else j--;
    }
    for(i=1;i<=m[n1][n2];i++)
        printf("%d ",sir2[i]);

    return 0;
}
