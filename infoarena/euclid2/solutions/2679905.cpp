#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc2(int a, int b)
{
    if (b == 0)
        return a;
    return cmmdc2(b, a % b);
}

int main()
{
    int T;
    int a, b;
    fin >> T;
    for (int i = 0; i < T; i++)
    {
        fin >> a >> b;
        fout << cmmdc2(a, b) << '\n';
    }
}