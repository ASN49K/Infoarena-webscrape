#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long a,b,i,n,m;

int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        while(b!=0)
        {
            m=b;
            b=a%b;
            a=m;
        }
        fout<<a<<"\n";
    }
}
