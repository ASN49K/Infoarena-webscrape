#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a, b, n, i;

int cmmdc(int a, int b)
{
    int c;
    while(b!=0)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    fin >> n;
    for(i=1; i<=n; i++)
    {
        fin >> a >> b;
        fout << cmmdc( a, b ) << '\n';
    }
    return 0;
}
