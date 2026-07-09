#include <iostream>
#include <fstream>
#define input "euclid2.in"
#define output "euclid2.out"
using namespace std;

ifstream fin(input);
ofstream fout(output);

int div(int a,int b)
{
    if(!b)return a;
    else return div(b,a%b);
}


int main()
{
    int t,a,b;
    fin>>t;
    for( ; t;--t)
    {
        fin>>a>>b;
        fout<<div(a,b)<<'\n';
    }
    return 0;
}
