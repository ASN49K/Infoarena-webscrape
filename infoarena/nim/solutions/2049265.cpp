#include<fstream>
using namespace std;
int main()
{
    ifstream fin("nim.in");
    ofstream fout("nim.out");
    int t,n,x,sol;
    fin>>t;
    while(t--)
    {
        fin>>n;
        sol=0;
        for(;n;n--)
        {
            fin>>x;
            sol^=x;
        }
        if(sol==0)fout<<"NU\n";
        else fout<<"DA\n";
    }
    return 0;
}
