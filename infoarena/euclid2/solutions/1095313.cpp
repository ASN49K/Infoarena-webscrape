#include <cstdio>

using namespace std;
int cmmdc(int x, int y)
{
    int aux;
    while(y != 0)
    {
        aux = y;
        y = x % y;
        x = aux;
    }
    return x;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int numar_perechi;
    scanf("%d",&numar_perechi);

    int a,b;

    for(int i = 0; i < numar_perechi; i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }

    fclose (stdin);
    fclose (stdout);
    return 0;
}


