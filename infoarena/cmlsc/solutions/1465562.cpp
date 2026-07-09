#include <fstream>

using namespace std;
int m,n;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int q,k,x[1024],y[1024],poz[1024],p=0;
    f>>m>>n;
    for(int i=1;i<=m;i++)f>>x[i];
    for(int j=1;j<=n;j++)f>>y[j];
    k=1;q=0;
    for(int i=1;i<=m;i++)
        for(int j=k;j<=n;j++)
         if(x[i]==y[j])
    {
        q++;k=j;poz[++p]=x[i];
    }
    g<<q<<'\n';
    for(int i=1;i<=p;i++)
       g<<poz[i]<<" ";
    f.close();g.close();
    return 0;
}
