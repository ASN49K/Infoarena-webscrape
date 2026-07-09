#include <iostream>
#include <fstream>

typedef unsigned long ulong;
using namespace std;

ulong cmmdc( ulong a, ulong b)
{
    if (!b)
        return a;
    else 
        return cmmdc(b,a%b);
}

int main()
{
    ulong t,a,b,i;
    ifstream fin;
    ofstream fout;
    
    fin.open("euclid2.in");
    fout.open("euclid2.out");    
    fin>>t;
    
    for (i=0;i<t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}