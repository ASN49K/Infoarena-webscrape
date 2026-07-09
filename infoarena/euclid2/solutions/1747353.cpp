#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t,i,a,b;

int cmmdc(int x, int y)
{
    if(y==0)
        return x;
    return cmmdc(y,y%x);
}


int main()
{
    fin>>t;
    for(i=1; i<=t; i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<' ';
    }

    fin.close();
    fout.close();
    return 0;
}
