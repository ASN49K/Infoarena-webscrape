#include <iostream>
#include <fstream>
using namespace std;
int t,n,nr,sol;
int main()
{
    int i;
    fstream f,g;
    f.open("nim.in",ios::in);
    g.open("nim.out",ios::out);
    f>>t;
    while(t--)
    {
        f>>n;
        f>>sol;
        for (i=1;i<n;i++)
        {
            f>>nr;
            sol=sol^nr;
        }
        if (sol==0)
            g<<"NU\n";
        else
            g<<"DA\n";
    }

}
