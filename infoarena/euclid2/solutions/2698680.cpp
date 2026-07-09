#include <iostream>
using namespace std;

int n;
int euclid(int a, int b)
{
    if (!b) return a;
    return euclid(b, a % b);
}
int main()
{
    int a, b;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        cout<<euclid(a, b)<<"\n";
    }
}
