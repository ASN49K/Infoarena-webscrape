#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid.in");
ofstream fout("euclid.out");

int cmmdc(int x, int y)
{
    if(y == 0)return(x);

    int r;
    while(y != 0)
    {
        r = y;
        y = x % y;
        x = r;
    }
}

int main()
{
    int T, a, b;

    fin >> T;
    for(int i = 0; i < T; ++ i)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }

    return(0);
}
