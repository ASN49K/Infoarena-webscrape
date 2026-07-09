#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
    int aux;
    while(b!=0){
        aux = a%b;
        a=b;
        b=aux;
    }
    return a;
}

int main()
{
    int t, a, b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for(int i=1; i<=t; i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a, b)<<endl;
    }
    return 0;
}
