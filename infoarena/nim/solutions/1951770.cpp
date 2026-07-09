#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");
    int n, t;
    f >> t;
    for( ; t; --t)
    {
        f >> n;
        int x, s=0;
        for(int i=0; i<n; ++i)
            f >> x, s = s ^ x;
        if(s)
            g << "DA" << '\n';
        else
            g << "NU" << '\n';
    }
    f.close();
    g.close();
    return 0;
}
