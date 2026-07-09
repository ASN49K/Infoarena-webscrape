#include <iostream>
int a,b,c;
using namespace std;
void euclid(int a, int b, int *d)
{
    if (b == 0) {
        *d = a;
    } else
        euclid(b, a % b, d);
}
int main()
{
    cin>>a>>b;
    euclid(a,b);

    return 0;
}
