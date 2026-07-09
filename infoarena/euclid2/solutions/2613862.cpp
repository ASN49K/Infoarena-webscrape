#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");

int cmmdc (int nr1, int nr2)
{
    while (nr2 != 0)
    {
        int rest = nr1 % nr2;
        nr1 = nr2;
        nr2 = rest;
    }
    return nr1;
}

int main()
{
    int n, nr1, nr2;
    fin >> n;

    for (int i = 1; i <= n; i++)
    {
        fin >> nr1 >> nr2;
        fout << cmmdc(nr1, nr2) << endl;
    }
    return 0;
}
