#include <fstream>
#include <iostream>
using namespace std;

int Cmmdc(int a, int b)
{
    int rest;
    while(b > 0)
    {
        rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

int main()
{
    ifstream fin("euclid.in");
    ofstream fout("euclid.out");

    int a, b, T, result;

    fin >> T;

    while(T--)
    {
        fin >> a >> b;
        result = Cmmdc(a, b);
        fout << result << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
