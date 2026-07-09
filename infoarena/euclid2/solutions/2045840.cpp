#include <iostream>
#include <fstream>

using namespace std;

unsigned long long int a,b;
int i,t;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    while(a && b)
    {
        if(a>b)
            a%=b;
        else
            b%=a;
    }
    if(a)
        return a;
    return b;
}

int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
