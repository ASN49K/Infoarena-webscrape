#include <iostream>
#include <fstream>

using namespace std;

int t,n,x,a;

int main()
{
    ifstream fin("nim.in");
    ofstream fout("nim.out");
    fin>>t;
    for(int i=0;i<t;i++)
    {
        fin>>n;
        x=0;
        for(int j=0;j<n;j++)
        {
            fin>>a;
            x=x^a;
        }
        if(x)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
    return 0;
}
