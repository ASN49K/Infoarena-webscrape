#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int n,m,a;
    fin>>n;
    for(int i=0;i<n;i++)
    {
        fin>>m;
        int sumNim=0;
        for(int j=0;j<m;j++)
        {
            fin>>a;
            sumNim= sumNim ^ a;
        }
        if(sumNim)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
    return 0;
}
