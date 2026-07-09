#include <stdio.h>

using namespace std;

int T,A,B;

int euclid(int a,int b)
{
    if (!b) return a;
    return euclid(b,a%b);
}

int main()
{
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);

    scanf("%d\n",&T);

    for (int i=1;i<=T;i++)
    {
        scanf("%d %d\n",&A,&B);
        printf("%d\n",euclid(A,B));
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
