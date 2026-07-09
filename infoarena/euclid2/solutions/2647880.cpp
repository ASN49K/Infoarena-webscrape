#include <iostream>
int main()
{
    int n , m;
    std :: cin >> n >> m;
    while(m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }
    std :: cout << n << std :: endl;
    return 0;
}`
