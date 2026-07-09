#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    int t,a,var;
    int xorsum=0;
    fin>>t;
    for(int i = 0;i<t;i++)
    {
        fin>>a;
        xorsum = 0;
        for(int j = 0;j<a;j++)
        {
            fin>>var;
            xorsum^=var;
        }
        if(xorsum)
            fout<<"DA"<<'\n';
        else
            fout<<"NU"<<'\n';
    }
    return 0;
}
