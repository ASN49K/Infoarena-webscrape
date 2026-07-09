#include <iostream>
#include <fstream>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t, s;
    f >> t;
    for(int i = 1; i <= t; i++)
    {
        int n;
        s = 0;
        for(int j = 1; j <= n; j++)
        {
            int aux;
            f >>aux;
            s ^= aux;
        }

        if(s == 0) g << "NU" << '/n';
        else g << "DA" << '/n';
    }


    return 0;
}
