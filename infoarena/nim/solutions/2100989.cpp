#include <fstream>

using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int main()
{int n,t,nr,s;
in>>t;
while(t--)
{
    in>>n;
    s=0;
    for(int i=1;i<=n;i++)
        in>>nr,s=s^nr;

    if(s)
    out<<"DA"<<'\n';
    else out<<"NU"<<'\n';
}
    return 0;
}
