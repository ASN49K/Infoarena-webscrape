#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int T,i,t,n,sol,x;
int main()
{
    f>>T;
    for(t=1;t<=T;t++)
    {
        f>>n;
        for(i=1;i<=n;i++){
            f>>x;
            sol=sol^x;
        }
        if(sol==0)
            g<<"NU"<<'\n';
        else
            g<<"DA"<<'\n';
    }
    return 0;
}
