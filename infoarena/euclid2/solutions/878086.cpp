#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n,a,b,r,i;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a;
        fin>>b;
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout<<b<<"\n";
    }


    return 0;
}
