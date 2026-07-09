#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int i,a,b,r,n;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        while(b)
        {
            r=a%b;a=b;b=r;
        }
        fout<<a<<"\n";
    }
    return 0;
}
