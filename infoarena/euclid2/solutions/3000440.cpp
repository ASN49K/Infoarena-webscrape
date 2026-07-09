#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
{
    if(a < b)
    {
        swap(a, b);
    }

    for(int i = b; i > 0; i--)
    {
        if(a % i == 0 && b % i == 0)
        {
            return i;
        }
    }

    return 0;
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
