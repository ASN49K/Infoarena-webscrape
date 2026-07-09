#include <fstream>

using namespace std;
ifstream fin ("nim.in");
ofstream fout ("nim.out");

int t, n, s, x;

int main()
{
    fin>>t;
    for(int i=1; i<=t; i++)
    {
        fin>>n;
        fin>>x;
        s=x;
        for(int j=1; j<n; j++)
            {fin>>x; s=s^x;}
        if(s==0) fout<<"NU"<<'\n';
        else fout<<"DA"<<'\n';
    }
    return 0;
}
