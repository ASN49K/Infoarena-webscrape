#include <iostream>
#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int n,q,t,k;
int main()
{
    for(f>>n;n;--n)
    {
        t=k=0;
        for(f>>q;q;--q)
        {
            f>>t;
            k=k^t;
        }
        if(k)g<<"DA\n";
        else g<<"NU\n";
    }
}
