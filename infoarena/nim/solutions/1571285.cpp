#include <iostream>
#include <fstream>

using namespace std;

int n,t;

int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");
    f>>t;
    while(t--)
    {
        f>>n;
        int s=0,x;
        while(n--)
        {
            f>>x;
            s^=x;
        }
        if(s)
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    f.close();
    g.close();
    return 0;
}
