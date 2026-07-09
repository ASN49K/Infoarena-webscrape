#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int k, n, m, i, x;

int main()
{
    in >> k;

    for(i = 1; i <= k; ++ i)
    {
        in >> n >> m;
        while(n != 0)
        {
            x = n;
            n = m % n;
            m = x;
        }
        out << m << "\n";
    }
    return 0;
}
