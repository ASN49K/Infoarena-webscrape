#include <cstdio>
using namespace std;
FILE *f,*g;
int divm(int a,int b)
{
    int r=1;
    while(r)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    int t,aux,a,b,c;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d ",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d",&a,&b);
        if(a<b)
        {
            aux=a;
            a=b;
            b=aux;
        }
        c=divm(a,b);
        printf("%d\n",c);
    }
    return 0;
}
