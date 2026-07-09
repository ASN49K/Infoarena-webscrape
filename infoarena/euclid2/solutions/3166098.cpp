#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int main()
{
    int nrnr, numar1, numar2, i,j,d;
    fin>>nrnr;
    for(i=1;i<=nrnr;i++)
    {
        fin>>numar1;
        fin>>numar2;
        for(j=1;j<=numar1/2;j++)
        {
            if(numar1%j==0&&numar2%j==0)
                d=j;
        }
        fout<<d<<endl;
        d=0;
    }
    return 0;
}
