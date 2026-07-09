#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc (int nr1, int nr2){

    if (!nr2)
        return nr1;
    return cmmdc(nr2, nr1 % nr2);
}

int main()
{
    int n, nr1, nr2;
    fin >> n;

    for (int i = 1; i <= n; i++)
    {
        fin >> nr1 >> nr2;
        fout << cmmdc(nr1, nr2) << '\n';
    }
    return 0;
}
