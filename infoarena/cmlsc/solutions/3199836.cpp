#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1000000], m, n, f = 0, v[2049];

int main()
{
    in >> m >> n;
    int j;
    for(int i = 1; i <= m + n; i++)
    {
        in >> j;
        a[j]++;
        if(a[j] == 2)
        {
            f++;
            v[f] = j;
        }
    }
    out << f;
    out << endl;
    for(int i = 1; i <= f; i++)
    {
        out << v[i] << " ";
    }
    return 0;
}

