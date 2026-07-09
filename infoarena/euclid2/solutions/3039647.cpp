#include <iostream>
#include <fstream>
using namespace std;
int t,i,a,b,x;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        while(b!=0)
        {
            x=a%b;
            a=b;
            b=x;
        }
        fout<<a;
    }
}
