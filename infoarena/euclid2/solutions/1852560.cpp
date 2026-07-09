#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{   int n,a,b,i,r;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }
    return 0;
}
