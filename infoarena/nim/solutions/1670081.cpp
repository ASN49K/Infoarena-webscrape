#include <iostream>
#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int n, m, s;

int main()
{
    int x;
    f>>n;
    while(n--)
    {
        f>>m;
        f>>x;
        s = x;
        m--;
        while(m--)
        {
            f>>x;
            s = s^x;
        }
        if(s == 0) g<<"NU\n";
        else g<<"DA\n";
    }
    return 0;
}
