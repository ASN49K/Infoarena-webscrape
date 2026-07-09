#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int t,a,i,b,r,d=1,v[100000];
    ifstream fin("euclid2.in");
      fin>>t;
    ofstream fout("euclid2.out");
    for(i=1;i<=t;i++)
    {
        fin>>a;
        fin>>b;
        r=a%b;
        while (a%b!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout<<b<<endl;
    }
    return 0;
}
