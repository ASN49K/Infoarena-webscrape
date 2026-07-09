#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t,n,x,xorsum;

int main()
{
    fin >> t;
    while(t--)
    {
        xorsum=0;
        fin >> n;
        while(n--)
        {
            fin >> x;
            xorsum^=x;
        }
        fout << (xorsum?"DA\n":"NU\n");
    }
    return 0;
}
