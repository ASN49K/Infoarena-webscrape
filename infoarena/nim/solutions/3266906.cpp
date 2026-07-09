#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int q,n,x,a;
int main()
{
    fin>>q;
    while(q--)
    {
        fin>>n>>x;
        x=x^0;
        for(int i=2; i<=n; i++)
        {
            fin>>a;
            x^=a;
        }
        if(x==0)
            fout<<"NU"<<'\n';
        else fout<<"DA"<<'\n';
    }
    return 0;
}
