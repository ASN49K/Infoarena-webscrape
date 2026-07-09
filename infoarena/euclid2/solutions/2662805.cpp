#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T,a,b,rest,aux,i;
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>a>>b;
        if(a>b)
        {
            aux=a;
            a=b;
            b=aux;
        }
        while(b!=0)
        {
            rest=a%b;
            a=b;
            b=rest;
        }
        fout<<a<<endl;
    }
    return 0;
}
