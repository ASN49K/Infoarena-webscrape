#include <stdio.h>
using namespace std;

int n;


int Euclid(int a, int b)
{
        if(!b)
            return a;

        return Euclid(b, a % b);
}


void read()
{
    int i, a, b, d;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        scanf("%d %d",&a,&b);

        d = Euclid(a,b);

        printf("%d\n", d);
    }

}


int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    read();

    fclose(stdin);
    fclose(stdout);

    return 0;
}
