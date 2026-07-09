#include <iostream>
#include <fstream>
using namespace std;
int t,n,a,nimsum,i,j;
int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");

    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>n;
        nimsum=0;
        for (j=1;j<=n;j++)
        {
            f>>a;
            nimsum = nimsum^a;
        }
        if(nimsum) g<<"DA"<<'\n';
                else g<<"NU"<<'\n';
    }
    return 0;
}
