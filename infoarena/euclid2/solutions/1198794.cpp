#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a,b,t,x;
    ifstream fin ("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for (int i=1; i<=t; i++)
    {
        fin>>a>>b;
        while (a%b!=0)
        {
            x=a;
            a=b;
            b=x%b;
        }
        fout<<b<<"\n";

    }

    return 0;
}
