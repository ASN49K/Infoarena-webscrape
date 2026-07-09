#include <fstream>
#include <iostream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,a,b,i,r;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }
    return 0;
}
