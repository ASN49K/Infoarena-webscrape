#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
    int aux;
    while(b!=0)
    {
        aux=b;
        b=a%b;
        a=aux;
    }
    return a;
}

int euclid2(int a, int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}

int main()
{
    int n,a,b;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<euclid2(a,b)<<endl;
    }

    return 0;
}
