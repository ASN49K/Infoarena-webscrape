#include<cstdio>
using namespace std;
int gcd(int a, int b)
{
    if(a%b==0)
        {
        return b;}
    else if(b % a == 0)
    {
        return a;
        }
    return gcd(a%b, b%a);
}
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int lel, a, b;
    scanf("%d", &lel);
    for(int sup=1;sup<=lel;sup++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
}
