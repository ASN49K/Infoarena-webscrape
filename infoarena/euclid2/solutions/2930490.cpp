#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t,i,r,a,b;
    fin>>t;
    for(i=1; i<=t; i++)
    {
        fin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }
    return 0;
}
