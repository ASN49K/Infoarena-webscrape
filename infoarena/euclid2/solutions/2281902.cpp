#include <iostream>
#include <fstream>

using namespace std;

int a,b;
int euclid(int a,int b)
{
 if(b==0)
    return a;
 return euclid(b,a%b);
}
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &t);
    for (; t; --t)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", euclid(a, b));
    }
    return 0;
}
