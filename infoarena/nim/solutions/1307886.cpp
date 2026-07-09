#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n,k,p,x;
    ifstream f("nim.in");
    ofstream g("nim.out");
    f>>k;
    for(int i=1;i<=k;i++)
    {
        f>>n;x=0;
        for(int j=1;j<=n;j++)
        {
            f>>p;
            x=x xor p;
        }
        if(x)
            g<<"DA\n";
        else g<<"NU\n";
    }
    return 0;
}
