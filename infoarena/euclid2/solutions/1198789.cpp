#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a,b,t;
    ifstream fin ("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for (int i=1; i<=t; i++)
    {
        fin>>a>>b;
        while(a!=b)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }
        fout<<b<<"\n";
    }

    return 0;
}
