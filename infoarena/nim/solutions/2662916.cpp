#include <fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int m,n,v,x;
int main()
{
    in>>m;
    for(int q=1;q<=m;++q)
    {
        in>>n;
        v=0;
        for(int i=1;i<=n;++i)
        {
            in>>x;
            v=v^x;
        }
        if(v!=0)
            out<<"DA"<<'\n';
        else
            out<<"NU"<<'\n';
    }
    return 0;
}
