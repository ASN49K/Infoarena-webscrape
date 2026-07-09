#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,i,n,x,j,y;
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>n>>x;
        for(j=2;j<=n;j++)
        {
            f>>y;
            x=x^y;
        }
        if(x!=0)g<<"DA"<<'\n';
        else g<<"NU"<<'\n';
    }
    return 0;
}
