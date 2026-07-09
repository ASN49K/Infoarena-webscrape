#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin ("euclid.in");
    ofstream fout ("euclid.out");
    int n,a,b,i,r;
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
