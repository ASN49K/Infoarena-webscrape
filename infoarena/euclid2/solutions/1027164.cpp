#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while(a > 0 && b > 0)
    {
        if(a > b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }
    return a > b ? a : b;
}

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    cout << gcd(a,b);
    return 0;
}
