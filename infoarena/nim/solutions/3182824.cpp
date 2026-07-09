#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n,m,p,x,y,t,r;
int main()
{   fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x;
        r=0;
        for(int j=1;j<=x;j++)
        {fin>>y;
       r=r^y;
        }
        if(r)
            fout<<"DA"<<'\n';
        else fout<<"NU"<<'\n';
    }
    return 0;
}
