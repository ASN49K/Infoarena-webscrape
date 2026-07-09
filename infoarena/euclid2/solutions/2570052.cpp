#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{
    while(b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{

    int a, b, t;
    fin>>t;
    while(t--)
    {
        fin>>a>>b;
        fout<<cmmdc(a, b)<<'\n';
    }
}
