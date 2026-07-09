#include <iostream>
#include <fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int main()
{
    int t;
    in >> t;
    while (t--)
    {
        int n;
        in >> n;
        int res = 0, x;
        for(int i = 1; i <= n; i++)
        {
            in >> x;
            res ^= x;
        }
        if(!res)
            out << "NU" << '\n';
        else
            out << "DA" << '\n';
    }
    return 0;
}
