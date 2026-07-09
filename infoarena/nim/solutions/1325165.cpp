#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");
int t,n,S;

void citire()
{
    int i,j,x;
    fin>>t;
    for(i=1; i<=t; i++)
    {
        S = 0;
        fin>>n;
        for(j=1; j<=n; j++)
        {
            fin>>x;
            S ^= x;
        }

        if(S > 0)
        {
            fout<<"DA\n";
        }
        else
        {
            fout<<"NU\n";
        }
    }
}

int main()
{
    citire();

    fin.close(); fout.close();
    return 0;
}
