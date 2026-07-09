#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int q, a, b;
    fin>>q;
    while(q--)
    {
        fin>>a>>b;
        while(b!=0)
        {
            int r = a%b;
            a = b;
            b = r;
        }
        fout<<a<<"\n";
    }
}
