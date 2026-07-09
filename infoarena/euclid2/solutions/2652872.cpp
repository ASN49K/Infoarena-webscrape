#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int CMMDC(int a,int b);

int main()
{
    int n,a,b,i;
    fin>>n;

    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<CMMDC(a,b)<<"\n";
    }

    return 0;
}

int CMMDC(int a,int b)
{
    if(!b) return a;
    else return CMMDC(b,a%b);
}
