#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int n,i,a,b,r,v[1001];
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        r=0;
        fin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        v[i]=a;

    }
    for(i=1;i<=n;i++)
        fout<<v[i]<<'\n';
    return 0;
}
