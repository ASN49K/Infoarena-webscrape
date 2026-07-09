#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int t,a,b;
    fin >> t;

    while (t)
    {
    fin>> a >> b;
        while (a!=b)
        {
        if (a>b)
        a=a-b;
        else
        b=b-a;
        }
    fout << a << endl;
    t=t-1;
    }
}
