#include<cstdio>
//ifstream f ("euclid2.in");
//ofstream g ("euclid2.out");
int main ()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n, a, b, c, i;
    //f>>n;
    scanf("%d",&n);
    for (i=1; i<=n; i++)
    {
        //f>>a>>b;
        scanf("%d%d",&a,&b);
        while (b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        //g<<a<<endl;
        printf("%d\n",a);
    }
    return 0;
}
