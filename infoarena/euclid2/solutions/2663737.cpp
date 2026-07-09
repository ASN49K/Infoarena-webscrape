//#include <fstream>

#include <stdio.h>
using namespace std;
int T, A, B;
int euclid(int a, int b)
{
    if (!b)
        return a;
    return euclid(b, a % b);
}
int main()
{
   // ifstream cin("euclid2.in");
    //ofstream cout("euclid2.out");
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", euclid(A, B));
    }
    return 0;
}
