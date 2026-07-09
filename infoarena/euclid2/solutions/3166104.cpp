#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int T,a,b,i,r;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>T;
    for(int i=1; i<=T;i++)
    {
        fin>>a;
        fin>>b;
        while(a!=0)
        {
            r=b%a;
            b=a;
            a=r;
        }
        fout<<b<<'\n';

    }
    return 0;
}
