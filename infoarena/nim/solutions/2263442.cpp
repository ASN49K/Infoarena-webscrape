#include <fstream>

using namespace std;
int t,n,i,j,x,sum;
int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");

    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>n; sum=0;
        for(j=1;j<=n;j++)
        {
            f>>x;
            sum^=x;
        }
        if(sum)
            g<<"DA"<<'\n';
        else
            g<<"NU"<<'\n';
    }

    return 0;
}
