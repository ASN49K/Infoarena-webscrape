#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    while(b != NULL)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int T, nr1, nr2;
    fin >> T;

    for (int i = 0; i < T; i++)
    {
        fin >> nr1 >> nr2;
        fout << cmmdc(nr1, nr2) << '\n';
    }

    return 0;
}
