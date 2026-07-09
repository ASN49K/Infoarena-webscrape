#include <iostream>

using namespace std;

int sir[1030],ma,a[1030],n;

int exista(int x,int j=1)
{
    if(j<=n)
        {
            if(x==a[j]) return 1;
            return exista(x,j+1);
        }
    else return 0;


}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int m,b[1030];

    scanf("%d%d",&n,&m);


    for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }

    for(int i=1;i<=m;i++)
        {
            scanf("%d",&b[i]);
            if(exista(b[i]))
                {
                    sir[ma++]=b[i];
                }
        }

    printf("%d\n",ma);

    for(int i=0;i<ma;i++)
        printf("%d ",sir[i]);



    return 0;
}
