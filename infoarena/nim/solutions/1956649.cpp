#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int T,N,x,rez;

int main()
{
    fin>>T;
    while(T--)
    {
        fin>>N;
        rez=0;
        for(int i=1;i<=N;++i)
        {
            fin>>x;
            rez=rez^x;
        }
        if(rez!=0) fout<<"DA"<<"\n";
        else fout<<"NU"<<"\n";
    }
}
