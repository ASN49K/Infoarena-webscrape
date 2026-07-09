#include <cstdio>
using namespace std;
int a , b , T;
int Euclid (int a , int b)
{
    int r = a % b;
    while (r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int main()
{
    freopen ("euclid2.in" , "r" , stdin);
    freopen ("euclid2.out" , "w" , stdout);

    scanf ("%d" , &T);
    for (int i = 1 ; i <= T ; ++i)
        scanf ("%d %d" , &a , &b) , printf ("%d\n" , Euclid (a , b));
    return 0;
}
