#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long int a,b,n,i,r;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        while(b)
        {
            r=b;
            b=a%b;
            a=r;
        }
        fout<<a<<'\n';
    }
    return 0;
}
