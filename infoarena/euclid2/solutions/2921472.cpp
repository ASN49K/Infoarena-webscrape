#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int T,a,b,aux;
    fin>>T;
    while(fin>>a>>b)
    {
        while(a%b!=0)
        {
            aux=b;
            b=a%b;
            a=aux;
        }
        fout<<b<<endl;
    }
    fin.close();
    fout.close();

    return 0;
}
