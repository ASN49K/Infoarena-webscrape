#include <fstream>

using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int main()
{
    int t,n,nr,i,j;
    int s=0;
    in>>t;
    for(i=1; i<=t; i++)
    {
        in>>n;
        for(j=1;j<=n;j++)
        {
            in>>nr;
            s^=nr;
        }
        if(s!=0)
        {
            out<<"DA"<<'\n';
        }
        else
            out<<"NU"<<'\n';
        s=0;
    }
    return 0;
}
