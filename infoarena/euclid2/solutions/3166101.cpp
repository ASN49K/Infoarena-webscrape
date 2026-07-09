#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int main()
{
    int nrnr, numar1, numar2,i,d;
    fin>>nrnr;
    for(i=1;i<=nrnr;i++)
    {
        fin>>numar1;
        fin>>numar2;
        while (numar2 !=0)
        {
            d=numar1%numar2;
            numar1=numar2;
            numar2=d;
        }
        fout<<numar1<<endl;
    }
    return 0;
}
