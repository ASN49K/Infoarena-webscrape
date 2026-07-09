#include <stdio.h>

using namespace std;
int n,k,x,y,aux,s,t;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        while(y!=0)
        {
            aux=y;
            y=x%y;
            x=aux;
        }
        printf("%d\n",x);
    }
    }






