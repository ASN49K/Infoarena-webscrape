#include <fstream>
using namespace std;

int main()
{
    ifstream fin("nim.in");
    ofstream fout("nim.out");
    long long t,x,n,sol=0;
    fin>>t;
    while(t)
    {
        fin>>n;
        for(; n; n--)
        {
            fin>>x;
            sol^=x;
        }
        if(sol==0) fout<<"NU\n";
        else fout<<"DA\n";
        --t;
    }
    return 0;
}
