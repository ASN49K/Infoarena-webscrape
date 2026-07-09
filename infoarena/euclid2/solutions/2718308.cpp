#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int teste,a,b,c;

int euclid(int a, int b)
{
    int c;
    while (b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    fin>>teste;
    while (teste)
    {
        fin>>a>>b;
        c=euclid(a,b);
        fout<<c<<'\n';
        teste--;
    }
    return 0;
}
