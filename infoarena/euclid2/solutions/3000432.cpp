#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int gcd_rec(int a, int b, int r)
{
    if(r == 0)
        return b;
    else
        return gcd_rec(b, r, b % r);
}

int main()
{
    int T;
    fin >>  T;
    for(int i = 0; i < T; i++)
    {
        int a, b;
        fin >> a >> b;
        if(a < b)
        {
            swap(a, b);
        }
        fout << gcd_rec(a, b, a % b) << endl;
    }

    return 0;
}
