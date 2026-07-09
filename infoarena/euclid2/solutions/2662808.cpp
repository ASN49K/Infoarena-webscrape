#include <iostream>
#include <fstream>

using namespace std;

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T,a,b,rest,aux,i;

void euclid(int a,int b)
{
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
}

int main()
{
    euclid(a,b);
    return 0;
}
