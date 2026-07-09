#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(long a, long b)
{
    if (b!=0) return euclid(b,a%b);
    else return a;
}
int main()
{
    long t;
    long a,b;
    fin>>t;
    while(t!=0)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<endl;
        t--;
    }
    fin.close();
    fout.close();
    return 0;
}
