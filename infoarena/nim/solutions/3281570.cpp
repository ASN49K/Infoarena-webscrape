#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int t,n,sol=0,x;
int main()
{
    fin>>t;

    while (t)
    {
        sol=0;
        fin>>n;

        while (n)
        {
            fin>>x;
            sol^=x;
            n--;
        }

        if (sol==0)
            fout<<"NU"<<"\n";
        else
            fout<<"DA"<<"\n";
        t--;
    }
    return 0;
}
