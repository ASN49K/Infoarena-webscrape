#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    int t,n,x,sol,i;
    fin>>t;
    while(t--)
    { fin>>n; sol=0;
       for(i=1;i<=n;++i)
        {fin>>x; sol=sol^x;}
        if(sol) fout<<"DA\n";
          else fout<<"NU\n";
    }
    return 0;
}
