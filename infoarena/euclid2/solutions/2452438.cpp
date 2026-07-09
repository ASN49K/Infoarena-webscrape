#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int T, a, b, i, r;
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>a>>b;
        while (b!=0)
        {
            r=b;
            b=a%b;
            a=r;
        }
        fout<<a<<"\n";
    }
    return 0;
}
