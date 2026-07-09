#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m,n,a[2030],b[1030],d[1030],p=1;

int main()
{
    f>>m>>n;
    for(int i=1;i<=m;i++)
        f>>a[i];
    for(int i=1;i<=n;i++)
        f>>b[i];

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j]){
                d[p]=a[i];
                p++;
            }
        }
    }

    g<<p-1<<"\n";
    for(int i=1;i<p;i++)
        g<<d[i]<<' ';


    f.close();
    g.close();
}
