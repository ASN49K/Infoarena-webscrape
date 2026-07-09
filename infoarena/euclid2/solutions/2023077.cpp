#include <fstream>

using namespace std;
int n,k;

bool v[20];

ifstream f("combinari.in");
ofstream g("combinari.out");

int valid(int x)
{
    int cnt=0;
    for(int i=1; i<=x; i++)
        cnt+=v[i];
    if(cnt==k)
        return 1;
    return 0;
}

void afisare()
{
    for(int i=1; i<=n; i++)
            if(v[i])
                g<<i<<" ";
    g<<'\n';
}

void bk(int x)
{
    for(int i=1; i>=0; i--)
    {
        v[x]=i;
        if(x==n)
                {
                    if(valid(x))
                        afisare();
                }
        else bk(x+1);
    }
}
int main()
{
    f>>n>>k;
    bk(1);
    return 0;
}
