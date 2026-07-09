#include<cstdio>
#include<algorithm>
using namespace std;
struct reactiv
{
    int a,b;
    friend bool operator < (const reactiv &p, const reactiv &q)
    {
        return p.a < q.a;
    }
};
reactiv v[8005],x,y;
int n,q;

reactiv intersectie(reactiv x, reactiv z)
{
    reactiv rez;
    if( x.a > z.a )
        rez.a=x.a;
    else if ( z.a >= x.a )
        rez.a=z.a;
    if( x.b < z.b )
        rez.b=x.b;
    else if( z.b <= x.a )
        rez.b=z.b;
    return rez;
}

int main()
{
    int i,j;
    freopen("reactivi.in","r",stdin);
    freopen("reactivi.out","w",stdout);
    scanf("%d", &n);
    for(i=1;i<=n;i++)
        scanf("%d%d", &v[i].a, &v[i].b);
    sort(v+1,v+n+1);
    for(i=1;i<=n;i++)
    {
        printf("%d %d\n",v[i].a,v[i].b);
    }
    x=v[1];
    for(i=2;i<=n;i++)
    {
        y=intersectie(x,v[i]);
        x=y;
        if(x.a>x.b)
        {
            printf("%d %d %d\n ",x.a,x.b,i);
            q++;
            x=v[i];
        }
    }
    q++;
    printf("%d",q);
    return 0;
}
