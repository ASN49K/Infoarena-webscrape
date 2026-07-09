#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t,n,rez,x;

int main()
{
    fin>>t;

    for(; t; t--)
    {
        fin>>n;
        rez=0;
        for(; n; n--)
        {
            fin>>x;
            rez^=x;
        }
        if(rez) fout<<"DA"<<'\n';
        else    fout<<"NU"<<'\n';
    }

    fin.close();
    fout.close();
    return 0;
}
