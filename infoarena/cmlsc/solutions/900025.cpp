#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
struct nod
{
    int inf;
    nod *adr;
}*s[10000];
int u[100],maxim=-100;
int main()
{
    int n,m,v[100],b[100],j,i,o;
    nod *d,*c;
    in>>n>>m;
    for(int i=1;i<=n;i++)
    in>>v[i];
    for(int i=1;i<=m;i++)
    in>>b[i];
    for(int k=1;k<=m;k++)
    {
        s[k]=new(nod);
        c=s[k];
        c->adr=0;
        o=0;
        for(j=k;j<=m;j++)
         {
            for(i=o+1;i<=n;i++)
            if(b[j]==v[i])
            {
                d=new(nod);
                c->inf=v[i];
                c->adr=d;
                d->adr=0;
                c=d;
                j++;
                o=i;
            }
                if(i==n)
                {
                    j++;
                    i=o;
                }
            }
            if(i>n) j=m;

        }
    for(i=1;i<=m;i++)
    {
        c=s[i];
        for(c;(c!=NULL)&&(c->adr!=NULL);c=c->adr) u[i]++;
    }
    for(i=1;i<=n;i++)
    {
        if(u[i]>maxim)
        {
            maxim=u[i];
            o=i;
        }
    }
    out<<maxim<<endl;
    c=s[o];
    for(c;((c!=NULL)&&(c->adr!=NULL));c=c->adr) out<<c->inf<<" ";

}
