#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int t;
bool rez()
{ int n,v[10005],s=0;

    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>v[i];
        s=s+(v[i]&1);
    }
    if(s%2!=0)
        return 0;
    for(int i=0;i<31;i++)
    { s=0;
        for(int j=1;j<=n;j++)
        {
            v[j]=v[j]>>1;
            s=s+(v[j]&1);
        }
    if(s%2!=0)
        return 0;
    }
return 1;
}

int main()
{
    fin>>t;
    for(int i=0;i<t;i++)
        if(rez()==1)
            fout<<"NU\n";
        else
            fout<<"DA\n";

    return 0;
}
