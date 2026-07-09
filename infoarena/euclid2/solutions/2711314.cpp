#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,T,d;


void euclid(int a, int b, int d)
{
    if (b == 0) {
        d = a;
    } else
        euclid(b, a % b, d);
}
int main()
{
    fin>>T;
    for(int i=1; i<T; i++)
    {
        fin>>a>>b;
        euclid (a, b, d);
        fout<<a<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
