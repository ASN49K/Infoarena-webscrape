#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

unsigned long long int a, b, t;

int impartire(int a, int b)
{
    if(!b)
        return a;
    return impartire(b, a%b);
}

void Euclid()
{
    fin >> t;
    for(int i = 1; i <= t; i++)
    {
        fin >> a >> b;
        fout << impartire(a, b) << '\n';
    }
}

int main()
{
    Euclid();
    return 0;
}
