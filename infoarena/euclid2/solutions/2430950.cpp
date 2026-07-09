#include <iostream>
#include <fstream>
using namespace std;
int a,b,T,d,aux1,aux2,i;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>a;
        fin>>b;
        aux1=a;
        aux2=b;
        while(aux1!=aux2)
        {
            if(aux1>aux2)
                aux1=aux1-aux2;
            else aux2=aux2-aux1;
        }
        fout<<aux1<<"\n";
    }

    return 0;
}
