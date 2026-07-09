#include <iostream>
#include <cstdio>

using namespace std;

void read(int &a, int &b)
{
    scanf("%d %d", &a, &b);
    if(a < b)
        swap(a, b);
}

int euclid(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T)
    {
        int a, b;
        read(a, b);
        printf("%d\n", euclid(a, b));
        T--;
    }
    return 0;
}
