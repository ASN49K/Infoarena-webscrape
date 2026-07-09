#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[100],b[100],c[100],n,m,viz[100];
void bkt()
{
    int i,j,p=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j]&&viz[a[i]]==0)
            {
                p++;
                c[p]=a[i];
                viz[a[i]]=1;
                i++;
            }
        }
    for(i=1;i<=p;i++)
        out<<c[i]<<" ";
}
int main()
{
    in>>m>>n;
    for(int i=1;i<=m;i++)
        in>>a[i];
    for(int i=1;i<=n;i++)
        in>>b[i];
    bkt();
    return 0;
}
