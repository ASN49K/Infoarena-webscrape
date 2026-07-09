#include <cstdio>

int n,m,a[1025],b[1025],mat[1025][1025];

void citire()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);

}

int maxim(int a, int b)
{
    if(a>b)
       return a;
    else
        return b;
}

void rez()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            {
                if(a[i]==b[j])
                   mat[i][j]=mat[i-1][j-1]+1;
                else
                    mat[i][j]=maxim(mat[i][j-1],mat[i-1][j]);
            }
}

void afisare(int i, int j)
{

    if(i<=1 && j<=1)
       return ;
    if(a[i]==b[j])
       {
           afisare(i-1,j-1);
           printf("%d ",a[i]);
       }
    else
        {
            if(mat[i][j-1]>mat[i-1][j])
               {if(j>1)
                  afisare(i,j-1);

                else
                    if(i>1)
                       afisare(i-1,j);
               }
            else
                {
                    if(i>1)
                       afisare(i-1,j);
                    else
                        if(j>1)
                           afisare(i,j-1);
                }
        }


}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    citire();
    rez();
    printf("%d\n",mat[n][m]);
    afisare(n,m);
    return 0;
}
