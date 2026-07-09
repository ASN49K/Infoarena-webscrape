#include <iostream>
#include <fstream>

using namespace std;


int eu (int a, int b)
{
    if (b==0)
    {
        return a;
    }
    else eu (b,a%b);
}

int main()
{
    int a,b,n;
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
        scanf("%d", &n);
        for (int i=1; i<=n; i++)
        {
            scanf("%d %d", &a,&b);
            printf("%d\n",eu(a,b));
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
