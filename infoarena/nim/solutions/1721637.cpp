#include <iostream>
#include <fstream>
using namespace std;
ifstream si("nim.in");
ofstream so("nim.out");
int main()
{
    int q,n,i,a,sol;
    si>>q;
    while(q--)
    {
        si>>n;
        sol=0;
        for(i=0;i<n;++i)
        {
            si>>a;
            sol^=a;
        }
        if(sol)
            so<<"DA\n";
        else
            so<<"NU\n";
    }
    return 0;

}
