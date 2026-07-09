#include <iostream>
#include <fstream>

#define input "euclid2.in"
#define output "euclid2.out"

using namespace std;

ifstream fin(input);
ofstream fout(output);
int t,a,b;

int cmmdc(int a,int b)
{
    if(!b)return a;
    return cmmdc(b,a%b);
}

int main()
{
    fin>>t;
    for( ; t;--t)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
}
