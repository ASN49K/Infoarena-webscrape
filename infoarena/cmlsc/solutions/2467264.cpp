#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void citire(int *v,int n)
{
    for(int i=0;i<n;++i)
        f>>v[i];
}

int main()
{
    int n,m,x[100],y[100],v[100],k=0;
    f>>n>>m;
    citire(x,n);
    citire(y,m);
    int res=0,pos=0;
    for(int i=0;i<n;++i)
    {
        for(int j=pos;j<m;++j)
            if(x[i]==y[j])
        {
            pos=j+1;
            ++res;
            v[k++]=x[i];
            break;
        }
    }
    g<<res<<'\n';
    for(int i=0;i<k;++i)
        g<<v[i]<<' ';

    return 0;
}
