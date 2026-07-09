#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{long i,s,t,n,x;
    fin>>t;
    while(t--)
    {
        fin>>n;
        s=0;
        for(i=1;i<=n;i++)
        {
            fin>>x;s^=x;
        }
        if(s)fout<<"DA\n";
        else fout<<"NU\n";

    }
}
