#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t, a, b;
int euclid(int a, int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    fin>>t;
    for(int i=1; i<=t; i++)
    {
        fin>>a>>b;
        fout<<euclid(a, b)<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}