#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
{
    if(b > a)
    {
        swap(a, b);
    }

    if(b == 0)
        return a;

    int r = a % b;
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int main()
{
    int T;
    fin >>  T;
    for(int i = 0; i < T; i++)
    {
        int a, b;
        fin >> a >> b;
        fout << gcd(a, b) << endl;
    }

    return 0;
}
