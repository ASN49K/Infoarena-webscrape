#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    long long unsigned int a, b;
    short t;
    fin>>t;
    for(int i=0;i<t;++i)
    {
        fin>>a>>b;
        int d=1;
        while(d!=0)
        {
            d=a%b;
            a=b;
            b=d;
        }
        fout<<a<<"\n";
    }
}
