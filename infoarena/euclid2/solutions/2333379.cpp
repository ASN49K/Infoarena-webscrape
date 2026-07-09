#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int t;
    fin>>t;
    for(int i=1; i<=t; i++)
    {
        int a,b;
        fin>>a>>b;
        fout<<euclid(a,b)<<"\n";

    }
    return 0;
}
