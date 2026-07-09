#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a,b,x,r,i,aux;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>x;
    for (i=1;i<=x;i++)
    {
        fin>>a;
        fin>>b;
        if (b>a)
        {
            aux=b;
            b=a;
            a=aux;
        }
        r=a%b;
        while (r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout<<b<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
