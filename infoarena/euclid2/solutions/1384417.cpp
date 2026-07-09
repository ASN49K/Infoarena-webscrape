#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    while (b)
    {
        int aux=b;
        b=a%b;
        a=aux;
    }
    return a;
}

int main()
{
    int a,b,t;
    fin>>t;
    for(int i=1; i<=t; i++){
    fin>>a>>b;
    fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
