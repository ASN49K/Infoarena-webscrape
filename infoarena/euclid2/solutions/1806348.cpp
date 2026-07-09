#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int N;

int euclid(int a,int b)
{
    if(!b) return a;
    return euclid(b,a%b);
}

int main()
{
    fin>>N;
    for(int i=1;i<=N;++i)
    {
        int a,b;
        fin>>a>>b;
        fout<<euclid(a,b)<<"\n";
    }
}
