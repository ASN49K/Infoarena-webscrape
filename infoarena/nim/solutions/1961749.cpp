#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n,xorlet,a,nr;
int main()
{
    fin>>nr;
    for(int k=1;k<=nr;k++)
    {
        fin>>n;xorlet=0;
        for(int j=1;j<=n;j++)
        {
            fin>>a;
            xorlet=xorlet^a;
        }
        if(xorlet>0)
            fout<<"DA"<<'\n';
        else fout<<"NU"<<'\n';
    }
    return 0;
}
