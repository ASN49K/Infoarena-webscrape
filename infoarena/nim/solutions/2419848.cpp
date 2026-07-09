#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int main()
{
    int m,n;
    fin>>m;
    for (int r=0;r<m;r++)
    {
        fin>>n;
        int sum=0,x;
        for (int i=0;i<n;i++)
        {
            fin>>x;
            sum^=x;
        }
        if (sum>0)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
    return 0;
}
