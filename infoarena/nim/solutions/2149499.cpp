#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int main()
{
    int t,i,aux,n;
    f>>t;
    while(t--)
    {
        int sum=0;
        f>>n;
        for(i=1;i<=n;i++)
        {
            f>>aux;
            sum=sum^aux;
        }
        if(sum==0)
            g<<"NU"<<'\n';
        else
            g<<"DA"<<'\n';
    }
    return 0;
}
