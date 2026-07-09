#include<fstream>
using namespace std;
long n,m,i,j,v[1025],d,ma,aux,a[1025],b[1025],k;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
f>>n>>m;
if(m>n)
    {
        aux=m;
        m=n;
        n=aux;
    }
for(i=1;i<=n;i++)
    f>>a[i];
for(i=1;i<=m;i++)
    f>>b[i];
for(i=1;i<=m;i++)
    {d=0;
    for(j=1;j<=n;j++)
        {
            if(v[j]>d)
                d=v[j];
            if(a[j]==b[i])
                {
                    d++;
                    v[j]=d;
                }
            if(d>ma)
                ma=d;
        }
    }
g<<ma<<'\n';
k=1;
for(i=1;i<=n && k<=ma;i++)
    if(v[i]==k)
        {
            g<<a[i]<<" ";
            k++;;
        }
return 0;
}
