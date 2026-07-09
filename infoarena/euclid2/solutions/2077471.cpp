#include <fstream>
#include <iostream>


using namespace std;
long euclid(long long x,long long y)
{
    int t,r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main()
{
    long long x,y,z;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>x;
    for(int i=0;i<x;++i)
    {
        fin>>y>>z;
        fout<<euclid(y,z)<<"\n";


    }
    return 0;
}

