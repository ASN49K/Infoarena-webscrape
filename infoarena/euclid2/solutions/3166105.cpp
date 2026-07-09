#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int main()
{
    int nrnr, a, b, i, rest;
    fin >> nrnr;

    for (i=1;i<=nrnr;i++)
    {
        fin >> a;
        fin >> b;
        while (b!=0)
        {
            rest=a%b;
            a=b;
            b=rest;

        }
        fout << a << endl;
    }


    return 0;
}
