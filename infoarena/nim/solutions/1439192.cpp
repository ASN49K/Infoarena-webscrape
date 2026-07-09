#include <iostream>
#include <fstream>
using namespace std;
 ifstream fin("nim.in");
  ofstream fout("nim.out");
int t,n,a,sumxor;

int main()
{
    int i;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>n;
        for(int j=1;j<=n;j++)
        {
            fin>>a;
            sumxor=sumxor^a;
        }
        if(sumxor) fout<<"DA\n";
        else fout<<"NU\n";
    }
    return 0;
}
