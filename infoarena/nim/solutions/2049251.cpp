#include <fstream>
using namespace std;
int t,x,n,sol;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    fin>>t;
    while(t)
    {
        fin>>n;
        while(n)
        {
            fin>>x;
            sol^=x;
            n--;
        }
        if(sol==0) fout<<"NU\n";
        else fout<<"DA\n";
        t--;
    }
    return 0;
}
