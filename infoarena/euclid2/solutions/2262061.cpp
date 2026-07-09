#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a,b,T,r;

int main()
{
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>a>>b;
        do
        {
            r=a%b;
            a=b;
            b=r;
        }
        while(r);
        fout<<a<<'\n';
    }
    return 0;
}
