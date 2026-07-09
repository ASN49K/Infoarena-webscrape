#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");


int main()
{
    int n, t, i, x, y;
    fin >> t;
    while(t--)
    {
        fin >> n;
        x = 0;
        for(i = 1 ; i <= n ; i++)
        {
            fin >> y;
            x ^= y;
        }
        if(x)
            fout << "DA\n";
        else
            fout << "NU\n";
    }
}
