#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int q;

int cmmdc(int a, int b)
{
    if(!b) return a;
    return cmmdc(b,a%b);
}

int main()
{
    int a,b;
    fin>>q;
    while(q)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
        q--;
    }
    return 0;
}
