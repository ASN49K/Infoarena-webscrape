#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n, a, b;
int main()
{
    in >> n;
    for(int i = 1; i <= n; ++ i)
    {
        in >> a >> b;
        int c;
        while (b)
        {
            c = a % b;
            a = b;
            b = c;
        }
        out << a << '\n';
    }
    return 0;
}
