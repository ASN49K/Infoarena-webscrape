#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int t, S, val, i, n;
int main()
{
    fin>>t;
    while(t--)
    {
        fin>>n;
        S=0;
        for(i=1;i<=n;i++)
        {
            fin>>val;
            S=S ^ val;
        }
        if(S==0)
            fout<<"NU";
        else
            fout<<"DA";
        fout<<'\n';
    }
    return 0;
}
