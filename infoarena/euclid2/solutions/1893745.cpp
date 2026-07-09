#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    long int i,n,a,b,aux,r;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        if(a<b) {aux=a;a=b;b=aux;}
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<'\n';
    }
    return 0;
}
