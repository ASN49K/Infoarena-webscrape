#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid (long long a, long long b)
{
    long long e;
    while(b!=0)
    {
        e=b;
        b=a%b;
        a=e;
    }
    return a;
}
int main()
{
    long t;
    long long a,b;
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
