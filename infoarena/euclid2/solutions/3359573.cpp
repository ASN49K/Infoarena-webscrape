#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void oglinda();
int cmmdc(int a, int b);

int main()
{
    int n;
    fin>>n;
    for(int i=1;i<=n;++i)
    {
        int a,b;
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}

int cmmdc(int a, int b)
{
    int r;
    while(b != 0)
    {
        r=a%b;
        a=b;
        b=r;
    }

    return a;
}

void oglinda()
{
    char x;
    fin.get(x);
    fout<<x;
    if(x != ' ') oglinda();
    fout<<x;
}
