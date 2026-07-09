#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    while(b!=0)
    {
        return cmmdc(b,a%b);
    }
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n,i,a,b;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
