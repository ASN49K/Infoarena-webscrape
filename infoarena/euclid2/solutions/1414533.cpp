#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid.in");
ofstream g ("euclid.out");

int t, a, b;
int Euclid (int a,int b)
{
    if(!b)
        return a;
    return Euclid (b,a%b);
}
int main()
{
    f >> t;
    while (t--)
    {
        f >> a >> b;
        g << Euclid(a, b) << '\n';
    }
    f.close();
    g.close();
    return 0;
}
