#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b)
{
    int r;
    while((r = a%b) != 0){
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int T, a, b;
    scanf("%i", &T);

    while(T--){
        scanf("%i%i", &a, &b);
        printf("%i\n", gcd(a, b));
    }

    return 0;
}
