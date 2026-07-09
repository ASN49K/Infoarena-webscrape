#include <iostream>
#include <fstream>
using namespace std;
int a,b,T,d,r,i;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>a;
        fin>>b;
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
